#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(a>b){
            swap(a,b);
        }
        if((b-a)%10==0){
            printf("%d\n",(b-a)/10);
            continue;
        }
        printf("%d\n",(b-a)/10+1);
    }
    return 0;
}