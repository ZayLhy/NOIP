#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sgt[(500010<<2)];
int a[500010];
int dp[500010];
int ls(int x){
    return x<<1;
}
int rs(int x){
    return x<<1|1;
}
void build(int root,int l,int r){
    if(l==r){
        sgt[root]=a[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    sgt[root]=min(sgt[ls(root)],sgt[rs(root)]);
    return ;
}
int query(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0x3f3f3f3f;
    }
    if(l<=nl&&r>=nr){
        return sgt[root];
    }
    int mid = (nl+nr)>>1;
    return min(query(ls(root),nl,mid,l,r),query(rs(root),mid+1,nr,l,r));
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        if(i-m<1){
            dp[i]=a[i]-query(1,1,n,1,i-1);
            continue;
        }
        dp[i]=a[i]-query(1,1,n,i-m,i-1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}