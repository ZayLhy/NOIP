#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct Node{
    int val;
    int tag;
}sgt[800010];
int a[200010];
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
    if(sgt[root].tag){
        sgt[root].tag=0;
        sgt[ls(root)].val=(mid-l+1)-sgt[ls(root)].val;
        sgt[rs(root)].val=(r-mid)-sgt[rs(root)].val;
        sgt[ls(root)].tag^=1;
        sgt[rs(root)].tag^=1;
    }
    return ;
}
void change(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].val=(nr-nl+1)-sgt[root].val;
        sgt[root].tag^=1;
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
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        a[i+1]=s[i]-'0';
    }
    build(1,1,n);
    int p,l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p,&l,&r);
        if(p==0){
            change(1,1,n,l,r);
        }
        if(p==1){
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}