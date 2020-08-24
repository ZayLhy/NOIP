#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    long long n,ans=1;
    cin>>n;
    while(n>1){
        n>>=1;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}