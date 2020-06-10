#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010][1010];
int dp[1010][1010];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}