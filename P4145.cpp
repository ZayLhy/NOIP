#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int n,m;
struct Node
{
    int maxn;
    int val;
}sgt[400010];
int a[100010];
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
void update(int root){
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
    sgt[root].maxn=max(sgt[ls(root)].maxn,sgt[rs(root)].maxn);
    return ;
}
void build(int root,int l,int r){
    if(l==r){
        sgt[root].maxn=sgt[root].val=a[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root);
    return ;
}
void sprt(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return ;
    }
    if(nl==nr){
        sgt[root].val=sqrt(sgt[root].val);
        sgt[root].maxn=sqrt(sgt[root].maxn);
        return ;
    }
    int mid = (nl+nr)>>1;
    sprt(ls(root),nl,mid,l,r);
    sprt(rs(root),mid+1,nr,l,r);
    update(root);
    return ;
}
int querytot(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].val;
    }
    int mid = (nl+nr)>>1;
    return querytot(ls(root),nl,mid,l,r)+querytot(rs(root),mid+1,nr,l,r);
}
int querymax(int root,int nl,int nr,int l,int r){
if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].maxn;
    }
    int mid = (nl+nr)>>1;
    return max(querymax(ls(root),nl,mid,l,r),querymax(rs(root),mid+1,nr,l,r));
}
void change(int l,int r){
    if(l>r){
        swap(l,r);
    }
    if(querymax(1,1,n,l,r)==1){
        return ;
    }
    for(int i=l;i<=r;i++){
        sprt(1,1,n,i,i);
    }
    return ;
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    int k,l,r;
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&k,&l,&r);
        if(k==1){
            if(l>r){
                swap(l,r);
            }
            printf("%lld\n",querytot(1,1,n,l,r));
        }
        if(k==0){
            change(l,r);
        }
    }
    return 0;
}