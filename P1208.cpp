#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct milk{
    int p;
    int a;
    bool operator < (const milk &a){
        return p<a.p;
    }
}a[2000010];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a[i].p,&a[i].a);
    }
    sort(a+1,a+m+1);
    int ans=0;
    for(int i=1;n>0;i++){
        if(n>a[i].a){
            ans+=a[i].a*a[i].p;
        }
        else if(n<=a[i].a){
            ans+=n*a[i].p;
        }
        n-=a[i].a;
    }
    printf("%d\n",ans);
    return 0;
}