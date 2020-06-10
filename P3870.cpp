#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
    int val;
    int tag;
}sgt[400010];
int ls(int x){
    return x<<1;
}
int rs(int x){
    return x<<1|1;
}
void update(int root){
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
    return ;
}
void pushdown(int root,int l,int r){
    if(sgt[root].tag){
        int mid = (l+r)>>1;
        sgt[root].tag=0;
        sgt[ls(root)].tag^=1;
        sgt[rs(root)].tag^=1;
        sgt[ls(root)].val=(mid-l+1)-sgt[ls(root)].val;
        sgt[rs(root)].val=(r-mid)-sgt[rs(root)].val;
    }
    return ;
}
void change(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].tag^=1;
        sgt[root].val=(nr-nl+1)-sgt[root].val;
        return ;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    change(ls(root),nl,mid,l,r);
    change(rs(root),mid+1,nr,l,r);
    update(root);
    return ;
}
int query(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].val;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return query(ls(root),nl,mid,l,r)+query(rs(root),mid+1,nr,l,r);
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int typ,l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&typ,&l,&r);
        if(typ==1){
            printf("%d\n",query(1,1,n,l,r));
        }
        if(typ==0){
            change(1,1,n,l,r);
        }
    }
    return 0;
}