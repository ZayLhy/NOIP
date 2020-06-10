#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
const int N = 400000 + 10; 
const int mod = 10007;
struct Edge
{
    int f;
    int t;
}a[N];
int head[N],nxt[N],tot;
void add(int f,int t){
    a[++tot]=(Edge){f,t};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
int w[N];
int n;
int maxn=0,ans=0;
void solve(int s){
    int tot=0;
    int l=0,r=0;
    for(int k=head[s];k;k=nxt[k]){
        (ans+=tot*w[a[k].t])%=mod;
        (tot+=w[a[k].t])%=mod;
        if(w[a[k].t]>l){
            r=l;
            l=w[a[k].t];
            continue;
        }
        if(w[a[k].t]>r)
            r=w[a[k].t];
    }
    maxn=max(maxn,l*r);
}
signed main(){
    scanf("%lld",&n);
    for(int i=1,f,t;i<n;i++){
        scanf("%lld%lld",&f,&t);
        add(f,t);
        add(t,f);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    
    for(int k=1;k<=n;k++){
        solve(k);
    }
    printf("%lld %lld\n",maxn,(ans*2)%mod);
    return 0;
}