#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,x,y,n;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
        int fa=max(x,a-n),fb=max(y,b-n);
        if(fb>fa){
            swap(a,b);
            swap(x,y);
        }
        if((b-y)<n){
            n-=(b-y),b=y,a=max(x,a-n);
        }
        else b-=n;
        printf("%lld\n",1ll*a*b);
    }
    return 0;
}