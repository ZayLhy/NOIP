#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
struct Node{
    int val;
    int tag;
}sgt[800010];
int a[200010];
int n,m;
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
inline void update(int root){
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
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
    int mid = (l+r)>>1;
    sgt[ls(root)].val+=(sgt[root].tag*(mid-l+1));
    sgt[rs(root)].val+=(sgt[root].tag*(r-mid));
    sgt[ls(root)].tag+=sgt[root].tag;
    sgt[rs(root)].tag+=sgt[root].tag;
    sgt[root].tag=0;
    return ;
}
void add(int root,int nl,int nr,int l,int r,int k){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&nr<=r){
        sgt[root].val+=k*(nr-nl+1);
        sgt[root].tag+=k;
        return ;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    add(ls(root),nl,mid,l,r,k);
    add(rs(root),mid+1,nr,l,r,k);
    update(root);
    return ;
}
int query(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&nr<=r){
        return sgt[root].val;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return query(ls(root),nl,mid,l,r)+query(rs(root),mid+1,nr,l,r);
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    int l,r,k,typ;
    for(int i=1;i<=m;i++){
        scanf("%lld",&typ);
        if(typ==1){
            scanf("%lld%lld%lld",&l,&r,&k);
            add(1,1,n,l,r,k);
        }
        if(typ==2){
            scanf("%lld",&k);
            add(1,1,n,1,1,k);
        }
        if(typ==3){
            scanf("%lld",&k);
            add(1,1,n,1,1,-k);
        }
        if(typ==4){
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,1,n,l,r));
        }
        if(typ==5){
            printf("%lld\n",query(1,1,n,1,1));
        }
    }
    return 0;
}