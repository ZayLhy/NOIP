#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<int,int> buk;
int a[100010],n,b;
int flag;
int main()
{
//    freopen("P1627.in","r",stdin);
//    freopen("P1627.out","w",stdout);
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==b){
            flag=i;
        }
        if(a[i]>b){
            a[i]=1;
        }
        else if(a[i]<b){
            a[i]=-1;
        }
    }
    int ans=1;
    for(int i=(flag-1),sum=0;i>=1;i--){
        sum+=a[i];
        buk[sum]++;
        if(sum==0){
            ans++;
        }
    }
    for(int i=(flag+1),sum=0;i<=n;i++){
        sum+=a[i];
        if(sum==0){
            ans++;
        }
        ans+=buk[-sum];
    }
    printf("%d\n",ans);
    return 0;
}