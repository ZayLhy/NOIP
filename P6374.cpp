#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int lg[1000010];
int n,q;
void init(){
    for(int i=1;i<1000010;i++){
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
}
int head[1000010],nxt[1000010],tot;
struct Edge{
    int f;
    int t;
}edge[1000010];
void add(int f,int t){
    edge[++tot]=(Edge){f,t};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
int dep[1000010],fa[30][1000010],dfn[1000010],ndfn=0,size[1000010];
void dfs(int now, int nfa){
    size[now]=1;
    dfn[now]=++ndfn;
    dep[now]=dep[nfa]+1;
    fa[0][now]=nfa;
    for(int i=1;(1<<i)<=dep[now];i++){
        fa[i][now]=fa[i-1][fa[i-1][now]];
    }
    for(int i=head[now];i;i=nxt[i]){
        if(edge[i].t==nfa)
            continue ;
        dfs(edge[i].t,now);
        size[now]+=size[edge[i].t];
    }
    return ;
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    while(dep[x]>dep[y]){
        x=fa[lg[dep[x]-dep[y]]-1][x];
    }
    if(x==y){
        return x;
    }
    for(int i=lg[dep[x]]-1;i>=0;i--){
        if(fa[i][x]!=fa[i][y]){
            x=fa[i][x];
            y=fa[i][y];
        }
    }
    return fa[0][x];
}
inline bool check(int x,int z){
    return ( (dfn[x]>=dfn[z]) && (dfn[x]<=(dfn[z]+size[z]-1)) );
}
int query(int x,int nfa){
    if(x==nfa){
        return 0;
    }
    for(int i=lg[n]-1;i>=0;i--){
        if(dfn[fa[i][x]]>dfn[nfa]){
            x=fa[i][x];
        }
    }
    return size[x];
}
int main()
{
    init();
    freopen("a.in","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1,f,t;i<n;i++){
        scanf("%d%d",&f,&t);
        add(f,t);
        add(t,f);
    }
    dfs(1,0);
/*    cout<<"Size:";
    for(int i=1;i<=n;i++){
        cout<<size[i]<<" ";
    }
    cout<<endl;*/
    int ans;
    for(int i=1,a,b,c;i<=q;i++){
        ans=0;
        scanf("%d%d%d",&a,&b,&c);
        int Lca=lca(a,b);
/*        cout<<"A in C:";
        if(check(a,c)){
            cout<<"True";
        }
        if(!check(a,c)){
            cout<<"False";
        }
        cout<<"|";
        cout<<"B in C:";
        if(check(b,c)){
            cout<<"True";
        }
        if(!check(b,c)){
            cout<<"False";
        }
        cout<<"|";*/
        if(Lca==c){
            ans=n-(query(a,c)+query(b,c));
        }
        else if(check(a,c)&&(!check(b,c))){
            ans=n-query(a,c)-(n-size[c]);
        }
        else if((!check(a,c))&&check(b,c)){
            ans=n-query(b,c)-(n-size[c]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
