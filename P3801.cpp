#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int sgtx[400010],sgty[400010];
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
void update(int *sgt,int root){
    sgt[root]=sgt[ls(root)]+sgt[rs(root)];
    return ;
}
void change(int *sgt,int root,int nl,int nr,int l,int r){
    if(l>nr||nl>r){
        return ;
    }
    if(nl==nr){
        sgt[root]^=1;
        return ;
    }
    int mid = (nl+nr)>>1;
    change(sgt,ls(root),nl,mid,l,r);
    change(sgt,rs(root),mid+1,nr,l,r);
    update(sgt,root);
}
int query(int *sgt,int root,int nl,int nr,int l,int r){
    if(l>nr||nl>r){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root];
    }
    int mid = (nl+nr)>>1;
    return query(sgt,ls(root),nl,mid,l,r)+query(sgt,rs(root),mid+1,nr,l,r);
}
int n,m,q;
inline int work(int xa,int ya,int xb,int yb){
    int tmpa=query(sgtx,1,1,n,xa,xb);
    int tmpb=query(sgty,1,1,m,ya,yb);
    int ans=tmpa*(yb-ya+1)+tmpb*(xb-xa+1)-((tmpa*tmpb)<<1);
    return ans;
}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&q);
    int x,y,xa,ya,xb,yb,typ;
    for(int i=1;i<=q;i++){
        scanf("%lld",&typ);
        if(typ==1){
            scanf("%lld%lld",&x,&y);
            change(sgtx,1,1,n,x,x);
            change(sgty,1,1,m,y,y);
        }
        if(typ==2){
            scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
            printf("%lld\n",work(xa,ya,xb,yb));
        }
    }
    return 0;
}