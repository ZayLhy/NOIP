#include<cstdio>
#include<algorithm>
using namespace std;
int sgt[4000050];
int a[4000050];
int n,m;
inline int ls(int x){
	return x<<1;	
}
inline int rs(int x){
	return (x<<1)+1;
}
inline void update(int root){
	sgt[root]=max(sgt[ls(root)],sgt[rs(root)]);
	return ;
}
void build(int root,int l,int r){
	if(l==r){
		sgt[root]=a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(ls(root),l,mid);
	build(rs(root),mid+1,r);
	update(root);
	return ;
}
int query(int root,int nl,int nr,int l,int r){
	if(nl>r||l>nr){
		return 0;
	}
	if(l<=nl&&r>=nr){
		return sgt[root];
	}
	int mid = (nl+nr)>>1;
	return max(query(ls(root),nl,mid,l,r),query(rs(root),mid+1,nr,l,r));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int l,r;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,1,n,l,r));
	}
	return 0;
}