#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int a[10010];
int main()
{
    int l,m;
    scanf("%d%d",&l,&m);
    for(int i=0;i<=l;i++){
        a[i]=1;
    }
    for(int i=1,l,r;i<=m;i++){
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;i++){
            a[i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<=l;i++){
        ans+=a[i];
    }
    printf("%d\n",ans);
    return 0;
}