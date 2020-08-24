#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0){
        printf("0.00\n");
        return 0;
    }
    long long f1=1,f2=1,t;
    for(int i=2;i<=n;i++){
        t=f2;
        f2+=f1;
        f1=t;
    }
    printf("%.2f\n",(double)f1);
    return 0;
}