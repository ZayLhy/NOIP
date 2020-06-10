#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int nxt[1000010];
void getnxt(string s){
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
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    getnxt(s);
    int ans=0;
    cout<<n-nxt[n]<<endl;
    return 0;
}