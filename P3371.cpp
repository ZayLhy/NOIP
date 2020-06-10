#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 500000 + 10;
struct Edge
{
    int f;
    int t;
    int v;
}a[N];
int head[N],nxt[N],tot;
long long dis[N];
int n,m;
bool vis[N];
void add(int f,int t,int v){
    a[++tot]=(Edge){f,t,v};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
void init(){
    for(int i=1;i<=n;i++){
        dis[i]=2147483647;
        vis[i]=false;
    }
}
void spfa(int s){
    init();
    queue<int> Q;
    Q.push(s);
    dis[s]=0;
    vis[s]=true;
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        vis[now]=false;
        for(int i=head[now];i;i=nxt[i]){
            if(dis[a[i].t]>dis[now]+a[i].v){
                dis[a[i].t]=dis[now]+a[i].v;
                if(!vis[a[i].t]){
                    Q.push(a[i].t);
                    vis[a[i].t]=true;
                }
            }
        }
    }
}
int main(){
    int s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1,f,t,v;i<=m;i++){
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
    }
    spfa(s);
    for(int i=1;i<=n;i++){
        printf("%lld ",dis[i]);
    }
    putchar('\n');
    return 0;
}