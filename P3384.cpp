#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define int long long
const int N = 100000 + 10;

int mod, n, m, root, val[N]; //basic var for input

struct Edge
{ //begin link list
    int f;
    int t;
} edge[N << 1];
int nxt[N << 1], head[N << 1], cnt;
void add(int f, int t)
{
    edge[++cnt] = (Edge){f, t};
    nxt[cnt] = head[f];
    head[f] = cnt;
    return;
} //end link list

int w[N]; //point value for sgt
//begin sgt
struct Node
{
    int add;
    int val;
    Node()
    {
        add = 0;
    }
} sgt[N << 2];
int ls(int x)
{
    return x << 1;
}
int rs(int x)
{
    return x << 1 | 1;
}
void update(int root)
{
    sgt[root].val = (sgt[ls(root)].val + sgt[rs(root)].val) % mod;
}
void build(int root, int l, int r)
{
    if (l == r)
    {
        sgt[root].val = (w[l] + mod) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(root), l, mid);
    build(rs(root), mid + 1, r);
    update(root);
    return;
}
void pushdown(int root, int l, int r)
{
    int mid = (l + r) >> 1;
    sgt[ls(root)].val = (sgt[ls(root)].val + sgt[root].add * (mid - l + 1)) % mod;
    sgt[rs(root)].val = (sgt[rs(root)].val + sgt[root].add * (r - mid)) % mod;
    sgt[ls(root)].add = (sgt[ls(root)].add + sgt[root].add) % mod;
    sgt[rs(root)].add = (sgt[rs(root)].add + sgt[root].add) % mod;
    sgt[root].add = 0;
    return;
}
void add(int root, int nl, int nr, int l, int r, int k)
{
    if (nl > r || l > nr)
    {
        return;
    }
    if (nl >= l && nr <= r)
    {
        sgt[root].val = (sgt[root].val + k * (r - l + 1)) % mod;
        sgt[root].add = (sgt[root].add + k) % mod;
        return;
    }
    pushdown(root, nl, nr);
    int mid = (nl + nr) >> 1;
    add(ls(root), nl, mid, l, r, k);
    add(rs(root), mid + 1, nr, l, r, k);
    update(root);
    return;
}
int query(int root, int nl, int nr, int l, int r)
{
    if (nl > r || l > nr)
    {
        return 0;
    }
    if (nl >= l && r >= nr)
    {
        return sgt[root].val;
    }
    pushdown(root, nl, nr);
    int mid = (nl + nr) >> 1;
    return (query(ls(root), nl, mid, l, r) + query(rs(root), mid + 1, nr, l, r)) % mod;
} //end sgt

int dep[N], fa[N], siz[N], top[N], hson[N], dfn[N], ndfn; //begin cut tree
void dfs1(int now, int nfa, int depth)
{
    dep[now] = depth;
    fa[now] = nfa;
    siz[now] = 1;
    int to, maxsiz = -1;
    for (int i = head[now]; i; i = nxt[i])
    {
        to = edge[i].t;
        if (to == nfa)
        {
            continue;
        }
        dfs1(to, now, depth + 1);
        siz[now] += siz[to];
        if (siz[to] > maxsiz)
        {
            maxsiz = siz[to];
            hson[now] = to;
        }
    }
}
void dfs2(int now, int topf)
{
    dfn[now] = ++ndfn;
    w[ndfn] = val[now];
    top[now] = topf;
    if (!hson[now])
    {
        return;
    }
    dfs2(hson[now], topf);
    int to;
    for (int i = head[now]; i; i = nxt[i])
    {
        to = edge[i].t;
        if (to == fa[now] || to == hson[now])
        {
            continue;
        }
        dfs2(to, to);
    }
} //end cut tree

//begin tree operation
void addp2p(int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        add(1, 1, n, dfn[top[x]], dfn[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    add(1, 1, n, dfn[x], dfn[y], k);
    return;
}
void addst(int x, int k)
{
    add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, k);
}
int qp2p(int x, int y)
{
    int res = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        res = (res + query(1, 1, n, dfn[top[x]], dfn[x])) % mod;
        x = fa[top[x]];
    //    printf("res:%lld\n",res);
    }
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    res = (res + query(1, 1, n, dfn[x], dfn[y])) % mod;
    return res;
}
int qst(int x)
{
    return query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1);
} //end tree operation

signed main()
{
    freopen("a.in","r",stdin);
    scanf("%lld%lld%lld%lld", &n, &m, &root, &mod);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
        val[i] %= mod;
    }
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%lld%lld", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs1(root, 0, 1);
    dfs2(root, 0);
    build(1, 1, n);
    for (int i = 1, opt, x, y, k; i <= m; i++)
    {
        scanf("%lld", &opt);
        if (opt == 1)
        {
            scanf("%lld%lld%lld", &x, &y, &k);
            addp2p(x, y, k % mod);
        }
        if (opt == 2)
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", qp2p(x, y));
        }
        if (opt == 3)
        {
            scanf("%lld%lld", &x, &k);
            addst(x, k % mod);
        }
        if (opt == 4)
        {
            scanf("%lld", &x);
            printf("%lld\n", qst(x));
        }
    }
    return 0;
}