#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,V;
int c[200010];
int v[200010];
int dp[200010];
int main(){
    scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=c[i];j<=V;j++){
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
        }
    }
    printf("%d\n",dp[V]);
    return 0;
}