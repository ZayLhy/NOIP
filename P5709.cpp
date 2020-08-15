#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int m,t,s;
    scanf("%d%d%d",&m,&t,&s);
    if(t==0){
        printf("0\n");
        return 0;
    }
    if(s%t==0){
        printf("%d\n",max(0,m-(s/t)));
        return 0;
    }
    printf("%d\n",max(0,m-1-(s/t)));
    return 0;
}