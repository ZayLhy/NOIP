#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
void work(){
    string a;
    map<char,int> M;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int i=0;i<a.length();i++){
            M[a[i]]++;
        }
    }
    for(int i=0;i<26;i++){
        if(M.count('a'+i)>0){
            if(M['a'+i]%n!=0){
                cout<<"NO"<<endl;
                return ;
            }
        }
    }
    cout<<"YES"<<endl;
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        work();
    }
    return 0;
}