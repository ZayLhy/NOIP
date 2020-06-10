#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s;
string t;
int nxt[1000010];
int ans=0;
int main()
{
    cin>>t;
    cin>>s;
    nxt[1]=0;
    for(int i=1;i<s.length();i++){
        int j=nxt[i];
        while(j&&s[i]!=s[j]){
            j=nxt[j];
        }
        if(s[i]==s[j]){
            nxt[i+1]=j+1;
        }
        else {
            nxt[i+1]=0;
        }
    }
    for(int i=0,j=0;i<t.size();i++){
        while(j&&t[i]!=s[j]){
            j=nxt[j];
        }
        if(t[i]==s[j]){
            j++;
        }
        if(j==s.size()){
            cout<<i-j+2<<endl;
        }
    }
    for(int i=1;i<=s.size();i++){
        cout<<nxt[i]<<" ";
    }
    cout<<endl;
    return 0;
}