#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
bool road[65][65][65];//f,t,2^k
long long dis[65][65];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
    }
    for(int i=1,f,t;i<=m;i++){
        scanf("%d%d",&f,&t);
        road[f][t][0]=dis[f][t]=1;
    }
    for(int t=1;t<=64;t++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(road[i][k][t-1]&&road[k][j][t-1]){
                        road[i][j][t]=true;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    printf("%lld\n",dis[1][n]);
    return 0;
}