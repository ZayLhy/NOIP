#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod = 1000000007;
struct Mar{
    int n;
    long long val[150][150];
    Mar(){
        memset(val,0,sizeof(val));
    }
    void init(){
        for(int i=1;i<=n;i++){
            val[i][i]=1;
        }
    }
    Mar operator * (const Mar &a){
        Mar ans;
        ans.n=n;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int j=1;j<=n;j++){
                    (ans.val[i][j]+=(val[i][k]*a.val[k][j]))%=mod;
                }
            }
        }
        return ans;
    }
};
void print(Mar a){
    int n=a.n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",a.val[i][j]);
        }
        putchar('\n');
    }
}
Mar qpow(Mar n,long long k){
    Mar ans,t=n;
    ans.n=t.n;
    ans.init();
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
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    Mar base;
    base.n=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&base.val[i][j]);
        }
    }
    print(qpow(base,k));
    return 0;
}