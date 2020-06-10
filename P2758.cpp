#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
string a;
string b;
int dp[2020][2020];
int main(){
//    freopen("a.in","r",stdin);
    cin>>a;
    cin>>b;
    for(int i=1;i<=a.length();i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=b.length();i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
                continue ;
            }
            if(a[i-1]!=b[j-1]){
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i-1][j-1]+1,dp[i][j-1]+1));
                continue ;
            }
        }
    }
    printf("%d\n",dp[a.length()][b.length()]);
    return 0;
}