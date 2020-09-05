#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int Min=-2e9,Max=2e9;
    string a;
    int n,tmp;
    char type;
    cin>>n;
    for(int i=1;i<=n;i++){
        a.clear();
        cin>>a>>tmp>>type;
        if(type=='Y'){
            if(a==">="){
                Min=max(Min,tmp);
            }
            if(a==">"){
                Min=max(Min,tmp+1);
            }
            if(a=="<="){
                Max=min(Max,tmp);
            }
            if(a=="<"){
                Max=min(Max,tmp-1);
            }
        }
        if(type=='N'){
            if(a=="<"){
                Min=max(Min,tmp);
            }
            if(a=="<="){
                Min=max(Min,tmp+1);
            }
            if(a==">"){
                Max=min(Max,tmp);
            }
            if(a==">="){
                Max=min(Max,tmp-1);
            }
        }
    }
    if(Max>=Min){
        cout<<Min<<endl;
        return 0;
    }
    cout<<"Impossible"<<endl;
    return 0;
}