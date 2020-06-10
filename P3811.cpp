#include<cstdio>
#include<cstring>
#include<algorithm>
long long n,p;
long long qpow(long long n,long long k){
    long long ans=1,t=n;
    while(k){
        if(k&1){
            (ans*=t)%=p;
        }
        (t*=t)%=p;
        k>>=1;
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&p);
    for(int i=1;i<=n;i++){
        printf("%lld\n",qpow(i,p-2)%p);
    }
}