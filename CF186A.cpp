#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
string a,b;
int main()
{
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a!=b){
        cout<<"NO"<<endl;
        return 0;
    }
    if(cnt==2){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}