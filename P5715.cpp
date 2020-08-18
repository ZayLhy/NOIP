#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a[4];
    for(int i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+3);
    for(int i=0;i<3;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}