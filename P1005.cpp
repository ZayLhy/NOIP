//高精，我用Python，显然这个不对
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110][110];
int dp[110][110][110];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int l=1,r=m;
    int pts=0;
    dp[1][1][0]=2*a[1][1];
    dp[1][1][1]=2*a[1][m];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1){
                continue;
            }
            for(int k=0;k<=1;k++){
                pts=(1<<i)*a[j][l];
                if(k){
                    pts=(1<<i)*a[j][r];
                }
                if(j==1){
                    dp[i][j][k]=max(dp[i-1][n][0]+pts,dp[i-1][n][1]+pts);
                    continue;
                }
                dp[i][j][k]=max(dp[i][j-1][0]+pts,dp[i][j-1][1]+pts);
            }
            l++;
            r--;
        }
    }
    printf("%d\n",max(dp[m][n][0],dp[m][n][1]));
    return 0;
}