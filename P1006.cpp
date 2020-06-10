#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[110][110];
int dp[120][120][120];//步数，A横坐标，B横坐标
int main(){
    //memset(dp,1,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int tot=n+m-1;
    dp[1][1][1]=a[1][1];
    for(int step=2;step<=tot;step++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((step-i+1)<1||(step-j+1)<1){
                    continue ;
                }
                dp[step][i][j]=max(max(max(dp[step-1][i][j],dp[step-1][i-1][j-1]),dp[step-1][i-1][j]),dp[step-1][i][j-1])+a[i][step-i+1]+a[j][step-j+1];
                if(i==j){
                    dp[step][i][j]-=a[i][step-i+1];
                }
            }
        }
    }
    printf("%d\n",dp[tot][n][n]);
    return 0;
}