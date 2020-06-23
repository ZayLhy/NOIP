#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int nxt[1000010];
void kmp(string t,string s){
    memset(nxt,0,sizeof(nxt));
    nxt[1]=0;
    int ans=0;
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
            ans++;
        }
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    int n;
    cin>>n;
    string a,b;
    for(int i=1;i<=n;i++){
        a.clear();
        b.clear();
        cin>>a>>b;
        kmp(b,a);
    }
    return 0;
}