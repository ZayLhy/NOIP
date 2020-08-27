#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const int MAXN = 1000010;
struct Edge
{
    int f,t;
}edge[MAXN];
int head[MAXN],nxt[MAXN],cnt;
int dep[MAXN];
void add(int f,int t){
    edge[++cnt]=(Edge){f,t};
    nxt[cnt]=head[f];
    head[f]=cnt;
    return ;
}
void dfs(int nfa,int x){
    dep[x]=dep[nfa]+1;
    for(int i=head[x];i;i=nxt[i]){
        if(edge[i].t==nfa){
            continue;
        }
        dfs(x,edge[i].t);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,f,t;i<=n;i++){
        cin>>f>>t;
        if(f==0&&t==0){
            continue;
        }
        add(i,f);
        add(i,t);
    }
    dep[1]=0;
    dfs(1,1);
    int maxd=0;
    for(int i=1;i<=n;i++){
        maxd=max(maxd,dep[i]);
    }
    cout<<maxd<<endl;
    return 0;
}