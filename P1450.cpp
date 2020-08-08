#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long dp[200010];
long long n;
long long c[5],d[2010][5],s[2010];
int main()
{
    for(int i=1;i<=4;i++){
        scanf("%lld",&c[i]);
    }
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){  
            scanf("%lld",&d[i][j]);
        }
        scanf("%lld",&s[i]);
    }
    dp[0]=1;
    for(int i=1;i<=4;i++){
        for(int j=c[i];j<200010;j++){
            dp[j]+=dp[j-c[i]];
        }
    }
    for(int i=1;i<=n;i++){
        long long ans=dp[s[i]];
        for(int b=1;b<=15;b++){
            int nows=s[i];
            int k=0;
            for(int t=b,j=1;t;t>>=1,j++){
                if(t&1){
                    k^=1;
                    nows-=(d[i][j]+1)*c[j];
                }
            }
            if(nows>=0){
                if(k){
                    ans-=dp[nows];
                }
                else {
                    ans+=dp[nows];
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}