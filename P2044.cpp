#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long m,a,c,x,n,g;
long long slowmul(long long a,long long b){
    long long ans=0;
    while(b){
        if(b&1){
            (ans+=a)%=m;
        }
        (a<<=1)%=m;
        b>>=1;
    }
    return ans;
}
struct Mar{
    long long val[10][10];
    long long n;
    Mar(){
        memset(val,0,sizeof(val));
    }
    Mar operator * (const Mar &a){
        Mar ans;
        ans.n=n;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int j=1;j<=n;j++){
                    (ans.val[i][j]+=slowmul(val[i][k],a.val[k][j]))%=m;
                }
            }
        }
        return ans;
    }
};
Mar qpow(Mar n,long long k){
    Mar ans,t=n;
    ans.val[1][1]=ans.val[2][2]=1;
    ans.n=2;
    while (k)
    {
        if(k&1){
            ans=ans*t;
        }
        t=t*t;
        k>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld%lld%lld",&m,&a,&c,&x);
    scanf("%lld%lld",&n,&g);
    Mar base;
    base.n=2;
    base.val[1][1]=a;
    base.val[1][2]=0;
    base.val[2][1]=base.val[2][2]=1;
    Mar fac;
    fac.n=2;
    fac.val[1][1]=x;
    fac.val[1][2]=c;
    fac.val[2][1]=fac.val[2][2]=0;
    printf("%lld\n",((fac*(qpow(base,n))).val[1][1])%g);
    return 0;
}