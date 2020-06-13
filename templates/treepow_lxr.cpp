#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<string>
#include<stack>
#include<vector>
#include<map>
#include<deque>
#define ll long long
#define N 100003
using namespace std;
struct Edge
{
	int nxt,to;
}edge[N<<1];
struct st
{
	int val,add;
}a[N<<2];
int n,m,r,mod,cnt,idx;
int s[N],w[N],head[N];
int dep[N],f[N],siz[N],son[N],id[N],top[N];
void addedge(int u,int v)
{
	edge[++cnt].nxt=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void push_up(int x){a[x].val=(a[ls(x)].val+a[rs(x)].val)%mod;}
void build(int x,int l,int r)
{
	a[x].add=0;
	if(l==r)
	{
		a[x].val=(w[l]+mod)%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	push_up(x);
}
void push_down(int x,int l,int r)
{
	int mid=(l+r)>>1;
	a[ls(x)].val=(a[ls(x)].val+a[x].add*(mid-l+1))%mod;
	a[rs(x)].val=(a[rs(x)].val+a[x].add*(r-mid))%mod;
	a[ls(x)].add=(a[ls(x)].add+a[x].add)%mod;
	a[rs(x)].add=(a[rs(x)].add+a[x].add)%mod;
	a[x].add=0;
}
void modify(int x,int l,int r,int nl,int nr,int k)
{
	if(nl<=l&&nr>=r)
	{
		a[x].val=(a[x].val+k*(r-l+1))%mod;
		a[x].add=(a[x].add+k)%mod;
		return;
	}
	int mid=(l+r)>>1;
	push_down(x,l,r);
	if(nl<=mid) modify(ls(x),l,mid,nl,nr,k);
	if(nr>mid) modify(rs(x),mid+1,r,nl,nr,k);
	push_up(x);
}
int query(int x,int l,int r,int nl,int nr)
{
	if(nl<=l&&nr>=r) return a[x].val;
	int res=0,mid=(l+r)>>1;
	push_down(x,l,r);
	if(nl<=mid) res=(res+query(ls(x),l,mid,nl,nr))%mod;
	if(nr>mid) res=(res+query(rs(x),mid+1,r,nl,nr))%mod;
	return res;
}
void dfs1(int x,int fa,int depth)
{
	dep[x]=depth;
	f[x]=fa;
	siz[x]=1;
	int to,maxx=-1;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		to=edge[i].to;
		if(to==fa) continue;
		dfs1(to,x,depth+1);
		siz[x]+=siz[to];
		if(siz[to]>maxx)
		{
			maxx=siz[to];
			son[x]=to;
		}
	}
}
void dfs2(int x,int topf)
{
	id[x]=++idx;
	w[idx]=s[x];
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	int to;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		to=edge[i].to;
		if(to==f[x]||to==son[x]) continue;
		dfs2(to,to);
	}
}
void updrange(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,1,n,id[top[x]],id[x],k);
		x=f[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	modify(1,1,n,id[x],id[y],k);
}
int qrange(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res=(res+query(1,1,n,id[top[x]],id[x]))%mod;
		x=f[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	res=(res+query(1,1,n,id[x],id[y]))%mod;
	return res;
}
void updson(int x,int k)
{
	modify(1,1,n,id[x],id[x]+siz[x]-1,k);
}
int qson(int x)
{
	return query(1,1,n,id[x],id[x]+siz[x]-1);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&mod);
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&s[i]);
		s[i]%=mod;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(r,0,1);
	dfs2(r,0);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			updrange(x,y,k%mod);
		}
		if(opt==2)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",qrange(x,y));
		}
		if(opt==3)
		{
			scanf("%d%d",&x,&k);
			updson(x,k%mod);
		}
		if(opt==4)
		{
			scanf("%d",&x);
			printf("%d\n",qson(x));
		}
	}
	return 0;
}
/*
Tips:
1.建树要在两次dfs之后
2.修改和查询的区间是节点的新编号(id[x]) 
3.线段树别写错了(
4.码量较大,写的时候应有耐心 
*/
