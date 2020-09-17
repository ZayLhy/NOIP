#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define int long long
using namespace std;
int mod = 0;
struct Mar
{
    void init(int N){
        n=N;
        for(int i=1;i<=n;i++){
            val[i][i]=1;
        }
    }
    int n;
    long long val[11][11];
    Mar operator* (const Mar &a) {
        Mar ans;
        ans.n=n;
        memset(ans.val,0,sizeof(ans.val));
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int j=1;j<=n;j++){
                    (ans.val[i][j]+=val[i][k]*a.val[k][j])%=mod;
                }
            }
        }
        return ans;
    }
};
Mar qpow(Mar n,int k){
    Mar ans,t=n;
    memset(ans.val,0,sizeof(ans.val));
    ans.init(t.n);
    while(k){
        if(k&1){
            ans=ans*t;
        }
        t=t*t;
        k>>=1;
    }
    return ans;
}
signed main()
{
    long long n,m;
    cin>>n>>m;
    mod = m;
    Mar ans,zy;
    ans.n=zy.n=3;
    memset(ans.val,0,sizeof(ans.val));
    memset(zy.val,0,sizeof(zy.val));
    ans.val[1][2]=ans.val[1][3]=zy.val[2][1]=zy.val[2][2]=zy.val[3][2]=zy.val[3][3]=1;
    long long f[20];
    f[0]=1;
    for(int i=1;i<=18;i++){
        f[i]=f[i-1]*10;
    }
    for(int i=1,times=0;;i++){
        zy.val[1][1]=f[i]%mod;
        times=min(n,f[i]-1)-f[i-1]+1;
        ans = ans * qpow(zy,times);
        if(f[i]-1>=n){
            break;
        }
    }
    cout<<ans.val[1][1]<<endl;
    return 0;
}
