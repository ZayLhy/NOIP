#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
struct Node{
    int ml; //左起区间长度
    int mr; //右起区间长度
    int md; //中间区间长度
    int val=0;
}sgt[80010];
inline int ls(int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
inline void update(int root,int l,int r,int mid){
    sgt[root].ml=sgt[ls(root)].ml;
    sgt[root].mr=sgt[rs(root)].mr;
    sgt[root].md=max(sgt[ls(root)].md,sgt[rs(root)].md);
    if(sgt[mid].val!=sgt[mid+1].val){
        sgt[root].md=max((sgt[ls(root)].mr+sgt[rs(root)].ml),sgt[root].md);
        if(sgt[ls(root)].ml==(mid-l+1)){
            sgt[root].ml+=sgt[rs(root)].ml;
        }
        if(sgt[rs(root)].mr==(r-mid)){
            sgt[root].mr+=sgt[ls(root)].mr;
        }
    }
    return ;
}
void build(int root,int l,int r){
    if(l==r){
        sgt[root].md=sgt[root].ml=sgt[root].mr=1;
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root,l,r,mid);
    return ;
}
void change(int root,int l,int r,int k){
    if(l>k||r<k){
        return ;
    }
    if(l==r&&l==k){
        if(sgt[l].val==1){
            sgt[l].val=0;
        }
        else if(sgt[l].val==0){
            sgt[l].val=1;
        }
        return ;
    }
    int mid = (l+r)>>1;
    change(ls(root),l,mid,k);
    change(rs(root),mid+1,r,k);
    update(root,l,r,mid);
    return ;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    int k;
    for(int i=1;i<=m;i++){
        scanf("%d",&k);
        change(1,1,n,k);
        int ans=max(max(sgt[1].ml,sgt[1].mr),sgt[1].md);
        printf("%d\n",ans);
    }
    return 0;
}