#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int n,k;
int dp[2020][2020];
int sum;
const int mod = 10000;
int main()
{
    scanf("%d%d",&n,&k);
    dp[1][0]=1;
    for(int i=2;i<=n;i++){\
        int sum=0;
        for(int j=0;j<=k;j++){
            sum+=dp[i-1][j];
            sum%=mod;
            dp[i][j]=sum;
            if(j>=(i-1)){
                ((sum-=dp[i-1][j-i+1])+=mod)%=mod;
            }
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}