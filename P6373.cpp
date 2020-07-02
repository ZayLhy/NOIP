#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define int long long
using namespace std;
string Ss;
int a[4000010],n,m;
struct Node{
    int i,o,oi,io,ioi;
    Node(){
        i=o=oi=io=ioi=0;
    }
    Node operator+(const Node &a){
        Node tmp;
        tmp.i=i+a.i;
        tmp.o=o+a.o;
        tmp.oi=oi+a.oi+o*a.i;
        tmp.io=io+a.io+i*a.o;
        tmp.ioi=ioi+a.ioi+i*a.oi+io*a.i;
//        return (Node){i+a.i , o+a.o , oi+a.oi+o*a.i , io+a.io+i*a.o , ioi+a.ioi+i*a.oi+io*a.i};
        return tmp;
    }
}sgt[4000010];
int ls(int x){
    return x<<1;
}
int rs(int x){
    return x<<1|1;
}
void update(int root){
    sgt[root]=sgt[ls(root)]+sgt[rs(root)];
}
void build(int root,int l,int r){
    sgt[root]=Node();
    if(l==r){
        if(a[l]==0){
            sgt[root].i=1;
            return ;
        }
        sgt[root].o=1;
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root);
    return ;
}
void change(int root,int nl,int nr,int l,int r,int k){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&nr<=r){
        sgt[root]=Node();
        if(k==0){
            sgt[root].i=1;
            return ;
        }
        sgt[root].o=1;
        return ;
    }
    int mid = (nl+nr)>>1;
    change(ls(root),nl,mid,l,r,k);
    change(rs(root),mid+1,nr,l,r,k);
    update(root);
    return ;
}
Node query(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return Node();
    }
    if(nl>=l&&nr<=r){
        return sgt[root];
    }
    int mid = (nl+nr)>>1;
    return query(ls(root),nl,mid,l,r)+query(rs(root),mid+1,nr,l,r);
}
signed main()
{
    cin>>n>>m;
    cin>>Ss;
    for(int i=0;i<Ss.length();i++){
        if(Ss[i]=='I'){
            a[i+1]=0;
        }
        else {
            a[i+1]=1;
        }
    }
    build(1,1,n);
    int typ,l,r;
    string Aa;
    for(int i=1;i<=m;i++){
        cin>>typ;
        if(typ==2){
            cin>>l>>r;
            printf("%lld\n",query(1,1,n,l,r).ioi);
        }
        if(typ==1){
            Aa.clear();
            cin>>l;
            cin>>Aa;
            if(Aa[0]=='I'){
                change(1,1,n,l,l,0);
            }
            else {
                change(1,1,n,l,l,1);
            }
        }
    }
    return 0;
}