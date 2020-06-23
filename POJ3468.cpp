#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N  = 400000 + 10;
struct Node{
	long long val;
	long long tag;
}sgt[N];
int a[N];
inline int ls(int x){
	return x<<1;
}
inline int rs(int x){
	return x<<1|1;
}
void update(int root){
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
	if(l<=nl&&r>=nr){
		sgt[root].tag+=k;
		sgt[root].val+=((nr-nl+1)*k);
		return ;
	}
	pushdown(root,nl,nr);
	int mid = (nl+nr)>>1;
	add(ls(root),nl,mid,l,r,k);
	add(rs(root),mid+1,nr,l,r,k);
	update(root);
}
long long query(int root,int nl,int nr,int l,int r){
	if(nl>r||l>nr){
		return 0;
	}
	if(l<=nl&&r>=nr){
		return sgt[root].val;
	}
	pushdown(root,nl,nr);
	int mid = (nl+nr)>>1;
	return query(ls(root),nl,mid,l,r)+query(rs(root),mid+1,nr,l,r);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1,l,r,k;i<=m;i++){
        char typ;
		cin>>typ;
        while(typ=='\n'||typ==' '){
            cin>>typ;
        }
        cin>>l>>r;
		if(typ=='C'){
			scanf("%d",&k);
			add(1,1,n,l,r,k);
		}
		if(typ=='Q'){
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}