#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod = 1000000007;
struct Mar{
    long long val[5][5];
    Mar (){
        memset(val,0,sizeof(val));
    }
    Mar operator * (const Mar &a){
        Mar ans;
        for(int i=1;i<=2;i++){
            for(int k=1;k<=2;k++){
                for(int j=1;j<=2;j++){
                    (ans.val[i][j]+=(val[i][k]*a.val[j][k]))%=mod;
                }
            }
        }
        return ans;
    }
};
Mar qpow(Mar n,long long k){
    Mar ans,t=n;
    ans.val[1][1]=ans.val[1][2]=1;
    while(k){
        if(k&1){
            ans=ans*t;
        }
        t=t*t;
        k>>=1;
    }
    return ans;
}
int main(){
    long long n;
    scanf("%lld",&n);
    if(n==1||n==2){
        printf("1\n");
        return 0;
    }
    Mar base;
    base.val[1][1]=base.val[1][2]=base.val[2][1]=1;
    printf("%lld\n",(qpow(base,n-2).val[1][1])%mod);
    return 0;
}