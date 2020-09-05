#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    for(int i=1,tmp;i<=t;i++){
        scanf("%d",&n);
        vector<int> a;
        for(int j=1;j<=n;j++){
            scanf("%d",&tmp);
            a.push_back(tmp);
        }
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==(i+1)){
                cnt++;
            }
        }
        if(cnt==n){
            cout<<0<<endl;
            continue;
        }
        if(cnt>0){
            cout<<2<<endl;
            continue;
        }
        cout<<1<<endl;
    }
    return 0;
}