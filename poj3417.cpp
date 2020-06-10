#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int N = 400000 + 10;
struct Edge
{
    int f;
    int t;
}a[N];
int n,m;
int dep[N],fa[N][30],lg[N];
int head[N],nxt[N],tot;
void add(int f,int t){
    a[++tot]=(Edge){f,t};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
void init(){
    for(int i=1;i<=n;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i)-1;
	}
}
void dfs(int x,int nfa){
    dep[x]=dep[nfa]+1;
	fa[x][0]=nfa;
	for(int i=1;(1<<i)<=dep[x];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=nxt[i]){
		int to=a[i].t;
		if(to==nfa){
			continue;
		}
		dfs(to,x);
	}
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
		swap(x,y);
	}
	while(dep[x]>dep[y]){
		x=fa[x][lg[dep[x]-dep[y]]];
	}
	if(x==y){
		return x;
	}
	for(int k=lg[dep[x]];k>=0;k--){
		if(fa[x][k]!=fa[y][k]){
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	return fa[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    int f,t;
    for(int i=1;i<n;i++){
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&f,&t);

    }

    return 0;
}