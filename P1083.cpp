#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
struct Node
{
    int val;
    int tag;
}sgt[4000010];
int a[1000010];
int n,m;
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
inline void update(int root){
    sgt[root].val=min(sgt[ls(root)].val,sgt[rs(root)].val);
    return ;
}
void build(int root,int l,int r){
    if(l==r){
        sgt[root].val=a[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root);
    return ;
}
void pushdown(int root,int l,int r){
    sgt[ls(root)].val-=sgt[root].tag;
    sgt[rs(root)].val-=sgt[root].tag;
    sgt[ls(root)].tag+=sgt[root].tag;
    sgt[rs(root)].tag+=sgt[root].tag;
    sgt[root].tag=0;
    update(root);
    return ;
}
void minu(int root,int nl,int nr,int l,int r,int k){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].val-=k;
        sgt[root].tag+=k;
        return ;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    minu(ls(root),nl,mid,l,r,k);
    minu(rs(root),mid+1,nr,l,r,k);
    update(root);
    return ;
}
int query(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0x7fffffff;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].val;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return min(query(ls(root),nl,mid,l,r),query(rs(root),mid+1,nr,l,r));
}
bool check(int l,int r,int k){
    if(query(1,1,n,l,r)<k){
        return false;
    }
    return true;
}
signed main(){
    freopen("a.in","r",stdin);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    int l,r,k;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&k,&l,&r);
        if(check(l,r,k)){
            minu(1,1,n,l,r,k);
            continue;
        }
        printf("-1\n%lld\n",i);
        return 0;
    }
    printf("0\n");
    return 0;
}