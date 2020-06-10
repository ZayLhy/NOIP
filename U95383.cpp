#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Edge{
    int f,t,v;
}a[200010];
int head[200010],nxt[200010],tot;
void add(int f,int t,int v){
    a[++tot]=(Edge){f,t,v};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
long long dis[50][50];
long long dislist[100010];
int n,m,q;
void dfs(int now,int fa){
    for(int i=head[now];i;i=nxt[i]){
        int t=a[i].t;
        if(t==fa){
            continue;
        }
        dislist[t]=dislist[now]^a[i].v;
        dfs(t,now);
    }
}
void work(){
    for(int i=1,f,t,v;i<=m;i++){
        scanf("%d%d%d",&f,&t,&v);
        dis[f][t]=v;
        dis[t][f]=v;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]^dis[k][j]&&(dis[i][k]!=0x3f3f3f3f3f3f3f3f&&dis[k][j]!=0x3f3f3f3f3f3f3f3f)){
                    dis[i][j]=dis[i][k]^dis[k][j];
                }
            }
        }
    }
    for(int i=1,f,t;i<=q;i++){
        scanf("%d%d",&f,&t);
        printf("%lld\n",dis[f][t]);
    }
    return ;
}
int main(){
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d",&n,&m,&q);
    if(n<=100){
        work();
        return 0;
    }
    for(int i=1,f,t,v;i<=m;i++){
        scanf("%d%d%d",&f,&t,&v);
        add(f,t,v);
        add(t,f,v);
    }
    dfs(1,0);
    for(int i=1,f,t;i<=q;i++){
        scanf("%d%d",&f,&t);
        printf("%lld\n",dislist[f]^dislist[t]);
    }
    return 0;
}