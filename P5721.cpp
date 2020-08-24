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
    int m=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%02d",m++);
        }
        printf("\n");
    }
    return 0;
}