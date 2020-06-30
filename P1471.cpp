#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Node{
    double val;//点值
    double tot;//平方和
    double tag;
}sgt[400010];
double a[100010];
int ls(int x){
    return x<<1;
}
int rs(int x){
    return x<<1|1;
}
void update(int root){
    sgt[root].tot=sgt[ls(root)].tot+sgt[rs(root)].tot;
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
    return ;
}
void build(int root,int l,int r){
    if(l==r){
        sgt[root].val=a[l];
        sgt[root].tot=sgt[root].val*sgt[root].val;
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root);
    return ;
}
void pushdown(int root,int l,int r){
    int mid=(l+r)>>1;
    sgt[ls(root)].tot+=(2*sgt[root].tag*sgt[ls(root)].val+(mid-l+1)*sgt[root].tag*sgt[root].tag);
    sgt[rs(root)].tot+=(2*sgt[root].tag*sgt[rs(root)].val+(r-mid)*sgt[root].tag*sgt[root].tag);
    sgt[ls(root)].val=sgt[ls(root)].val+sgt[root].tag*(mid-l+1);//这个要后算，我是sb！！！！！！
    sgt[rs(root)].val=sgt[rs(root)].val+sgt[root].tag*(r-mid);
    sgt[ls(root)].tag+=sgt[root].tag;
    sgt[rs(root)].tag+=sgt[root].tag;
    sgt[root].tag=0;
    return ;
}
void add(int root ,int nl,int nr,int l,int r,double k){
    if(nl>r||l>nr){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].tot+=2*k*sgt[root].val+(nr-nl+1)*k*k;
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
double queryval(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].val;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return queryval(ls(root),nl,mid,l,r)+queryval(rs(root),mid+1,nr,l,r);   
}
double querytot(int root,int nl,int nr,int l,int r){
    if(nl>r||l>nr){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].tot;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return querytot(ls(root),nl,mid,l,r)+querytot(rs(root),mid+1,nr,l,r); 
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1,typ,l,r;i<=m;i++){
        double k;//要用double！！！！！！！！！
        cin>>typ>>l>>r;
        if(typ==1){
            cin>>k;
            add(1,1,n,l,r,k);
        }
        if(typ==2){
            double ans=queryval(1,1,n,l,r)/(double)(r-l+1);
            printf("%.04f\n",ans);
        }
        if(typ==3){
            double ans=querytot(1,1,n,l,r)/(double)(r-l+1);
            double tmp=queryval(1,1,n,l,r)/(double)(r-l+1);
            tmp=tmp*tmp;
            ans-=tmp;
            printf("%.04f\n",ans);
        }
    }
    return 0;
}
//