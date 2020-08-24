#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
priority_queue<int> Q;
vector<int> Ans;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1,a,b,c;i<=n;i++){
        cin>>a>>b>>c;
        for(int j=1;j<=m;j++){
            int x=a*j*j+b*j+c;
            if(Q.size()<m){
                Q.push(x);
            }
            if(x<Q.top()){
                Q.pop();
                Q.push(x);
            }
            if(x>Q.top()){
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        Ans.push_back(Q.top());
        Q.pop();
    }
    reverse(Ans.begin(),Ans.end());
    for(int i=0;i<m;i++){
        cout<<Ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}