#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n,m;
const int MAXN = 200010;
int head[MAXN],nxt[MAXN],cnt;
struct Edge
{
    int f;
    int t;
    int v;
}edge[MAXN];
int dis[MAXN];
bool vis[MAXN];
void add(int f,int t,int v){
    edge[++cnt]=(Edge){f,t,v};
    nxt[cnt]=head[f];
    head[f]=cnt;
    return ;
}
void init(){
    for(int i=0;i<MAXN;i++){
        dis[i]=2147483647;
    }
}
struct Edge2{
    int id;
    int v;
    bool operator< (const Edge2 &a) const {
        return v>a.v;
    }
};
void dij(int s){
    init();
    priority_queue<Edge2> Q;
    Q.push((Edge2){s,0});
    dis[s]=0;
    while(!Q.empty()){
        int now=Q.top().id;
        Q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        for(int i=head[now];i;i=nxt[i]){
            if(dis[edge[i].t]>dis[now]+edge[i].v){
                dis[edge[i].t]=dis[now]+edge[i].v;
                Q.push((Edge2){edge[i].t,dis[edge[i].t]});
            }
        }
    }
}
int main()
{
    int s;
    scanf("%d%d",&m,&n);
    for(int i=1,f,t,v;i<=m;i++){
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
        add(t,f,v);
    }
    dij(n);
    printf("%d\n",dis[1]);
    return 0;
}