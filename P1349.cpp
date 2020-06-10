#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long q,p,A,B,n,m;
struct Mar {
    long long val[5][5];
    Mar() {
        memset(val,0,sizeof(val));
    }
    Mar operator * (const Mar &a){
        Mar ans;
        for(int i=1;i<=2;i++){
            for(int k=1;k<=2;k++){
                for(int j=1;j<=2;j++){
                    (ans.val[i][j]+=(val[i][k]*a.val[k][j]))%=m;
                }
            }
        }
        return ans;
    }
};
Mar qpow(Mar n,long long k){
    Mar ans,t=n;
    ans.val[1][1]=B;
    ans.val[1][2]=A;
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
    scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&A,&B,&n,&m);
    Mar base;
    base.val[1][1]=p;
    base.val[1][2]=1;
    base.val[2][1]=q;
    printf("%lld\n",qpow(base,n-2).val[1][1]);
    return 0;
}