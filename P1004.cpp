#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int a[15][15];
int dp[15][15][15][15];
int main(){
    scanf("%d",&n);
    int x,y,z;
    while(cin>>x>>y>>z){
        a[x][y]=z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    dp[i][j][k][l]=max(max(max(dp[i-1][j][k-1][l],dp[i][j-1][k-1][l]),dp[i-1][j][k][l-1]),dp[i][j-1][k][l-1])+a[i][j]+a[k][l];
                    if(i==k&&j==l){
                        dp[i][j][k][l]-=a[i][j];
                    }
                }
            }
        }
    }
    printf("%d\n",dp[n][n][n][n]);
    return 0;
}