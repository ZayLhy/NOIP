#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int a[100010];
struct Node
{
    int tag;
    int val;
} sgt[400010];
inline int ls(int x)
{
    return x << 1;
}
inline int rs(int x)
{
    return x << 1 | 1;
}
inline void update(int root)
{
    sgt[root].val = sgt[ls(root)].val + sgt[rs(root)].val;
    return;
}
void build(int root, int l, int r)
{
    if (l == r)
    {
        sgt[root].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(root), l, mid);
    build(rs(root), mid + 1, r);
    update(root);
    return;
}
inline void pushdown(int root, int l, int r)
{
    int mid = (l + r) >> 1;
    sgt[ls(root)].val = sgt[ls(root)].val + sgt[root].tag * (mid - l + 1);
    sgt[rs(root)].val = sgt[rs(root)].val + sgt[root].tag * (r - mid);
    sgt[ls(root)].tag += sgt[root].tag;
    sgt[rs(root)].tag += sgt[root].tag;
    sgt[root].tag = 0;
    return;
}
void add(int root, int nl, int nr, int l, int r, int k)
{
    if (nl > r || l > nr)
    {
        return;
    }
    if (nl >= l && r >= nr)
    {
        sgt[root].val += k * (nr - nl + 1);
        sgt[root].tag += k;
        return;
    }
    pushdown(root, nl, nr);
    int mid = (nl + nr) >> 1;
    add(ls(root), nl, mid, l, r, k);
    add(rs(root), mid + 1, nr, l, r, k);
    update(root);
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
    return query(ls(root), nl, mid, l, r) + query(rs(root), mid + 1, nr, l, r);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >=1; i--)
    {
        a[i] -= a[i-1];
    }
    build(1, 1, n);
    for (int i = 1, tmp, l, r, k, d; i <= m; i++)
    {
        scanf("%d", &tmp);
        if (tmp == 2)
        {
            scanf("%d", &l);
            printf("%d\n", query(1, 1, n, 1, l));
        }
        if (tmp == 1)
        {
            scanf("%d%d%d%d", &l, &r, &k, &d);
            add(1, 1, n, l, l, k);
            if(l+1<=r)
                add(1, 1, n, l + 1, r, d);
            if(r<n)
                add(1, 1, n, r + 1, r + 1, -1 * (k + d * (r - l)));
        }
    }
    return 0;
}