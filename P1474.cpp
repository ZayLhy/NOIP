#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
long long V[30];
long long dp[100010];
int main()
{
    int v,n;
    scanf("%d%d",&v,&n);
    for(int i=1;i<=v;i++){
        scanf("%lld",&V[i]);
    }
    dp[0]=1;
    for(int i=1;i<=v;i++){
        for(int j=V[i];j<=n;j++){
            dp[j]+=dp[j-V[i]];
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}