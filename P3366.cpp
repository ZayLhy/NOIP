#include<cstdio>
#include<algorithm>
using namespace std;
int ans=0;
int fa[200005<<1];
struct Edge{
	int fr;
	int to;
	int va;
};
Edge edge[200005<<1];
int cnt=0;
int n,m;
int nfr,nto;
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
bool cmp(Edge a,Edge b){
	return a.va<b.va;
}
void kru(){
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		nfr=find(edge[i].fr);
		nto=find(edge[i].to);
		if(nfr==nto){
			continue;
		}
		ans+=edge[i].va;
		fa[nto]=nfr;
		cnt++;
		if(cnt==n-1){
			break;
		} 
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].fr,&edge[i].to,&edge[i].va);
	}
	kru();
	printf("%d\n",ans);
	return 0;
}