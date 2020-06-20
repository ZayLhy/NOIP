#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<(n/2-1)/2<<endl;
    return 0;
}