#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
long long t,n,m,p;
int main()
{
    cin>>t>>n>>m>>p;
    long long ans=1;
    for(long long i=n-2*m+2;i<=(n-m+1);i++){
        (ans*=i)%=p;
    }
    cout<<ans<<endl;
    return 0;
}