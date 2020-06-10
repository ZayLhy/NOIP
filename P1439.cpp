#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[200010];
int b[200010];
int Map[200010];
int dp[200010];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        Map[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++){
        dp[i]=0x3f3f3f3f;
        a[i]=Map[b[i]];
    }
    for(int i=1;i<=n;i++){
        dp[lower_bound(dp+1,dp+n+1,a[i])-dp]=a[i];
    }
    cout<<lower_bound(dp+1,dp+n+1,0x3f3f3f3f)-dp-1<<endl;
    return 0;
}