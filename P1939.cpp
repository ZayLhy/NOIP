#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
const long long mod = 1000000007;
struct Mar{
    int n;
    long long val[10][10];
    Mar operator * (const Mar &a){
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
    void init(int N){
        n=N;
        for(int i=1;i<=n;i++){
            val[i][i]=1;
        }
    }
};
void print(Mar a){
    for(int i=1;i<=a.n;i++){
        for(int j=1;j<=a.n;j++){
            printf("%lld ",a.val[i][j]);
        }
        putchar('\n');
    }
    return ;
}
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
int main(){
    int T;
    scanf("%d",&T);
    long long n;
    for(int i=1;i<=T;i++){
        scanf("%lld",&n);
        if(n<=3){
            printf("1\n");
            continue ;
        }
        Mar base;
        memset(base.val,0,sizeof(base.val));
        base.n=3;
        base.val[1][1]=base.val[1][3]=base.val[2][1]=base.val[3][2]=1;
        printf("%lld\n",qpow(base,n).val[2][1]);
    }
    return 0;
}