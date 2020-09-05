#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int dp[6][50001];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i][n]<<" ";
    }
    return 0;
}