#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0,tmp;i<n;i++){
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]==a[i+1]){
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}