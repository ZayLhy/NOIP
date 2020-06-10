#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> a;
int main()
{
    int n,m;
    string tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        tmp.clear();
        cin>>tmp;
        a[tmp]=0;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        tmp.clear();
        cin>>tmp;
        if(a.count(tmp)!=0){
            if(a[tmp]==0){
                a[tmp]=1;
                printf("OK\n");
                continue;
            }
            if(a[tmp]!=0){
                printf("REPEAT\n");
                continue;
            }
        }
        printf("WRONG\n");
    }
    return 0;
}