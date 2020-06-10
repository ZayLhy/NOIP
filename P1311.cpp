#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
struct Res{
    int color;
    int val;
}a[4000010];
int n,k,p;
long long buk[110];
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].color,&a[i].val);
    }
    int pos=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].val<=p){
            for(int j=i;j>pos;j--){
                buk[a[j].color]++;
            }
            pos=i;
            ans+=buk[a[i].color]-1;
            continue;
        }
        ans+=buk[a[i].color];
    }
    printf("%lld\n",ans);
    return 0;
}