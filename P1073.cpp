#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1000000 + 10;
const int INF = 0x3f3f3f3f;
struct Edge{
    int f;
    int t;
}a[N];
int head[N],nxt[N],tot;//graph
int cost[N];//cost
int minx[N],dp[N];//for dp
int n,m;
bool flag=true;
void add(int f,int t){
    a[++tot]=(Edge){f,t};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
void dfs(int prev,int minn,int now){//the-prev-one,now-minimum-cost,now-point
    flag=true;
    minn=min(minn,cost[now]);
    if(minx[now]>minn){
        minx[now]=minn;
        flag=false;
    }
    int maxn=max(dp[prev],cost[now]-minn);
    if(dp[now]<maxn){
        dp[now]=maxn;
        flag=false;
    }
    if(flag){
        return ;
    }
    for(int i=head[now];i;i=nxt[i]){
        dfs(now,minn,a[i].t);
    }
    return ;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        minx[i]=INF;
    }
    for(int i=1,f,t,typ;i<=m;i++){
        scanf("%d%d%d",&f,&t,&typ);
        add(f,t);
        if(typ==2){
            add(t,f);
        }
    }
    dfs(0,INF,1);
    printf("%d\n",dp[n]);
    return 0;
}