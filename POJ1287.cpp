#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Bcj{
    int fa[100010];
    void clear(){
        for(int i=0;i<100010;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        if(fa[x]==x){
            return x;
        }
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        int a=find(x);
        int b=find(y);
        fa[a]=b;
        return ;
    }
    bool check(int x,int y){
        return find(x)==find(y);
    }
}b;
struct Edge{
    int f;
    int t;
    int v;
    bool operator < (const Edge &a) const {
        return v<a.v;
    }
}edge[100010];
void kru(int n,int m){
    b.clear();
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        if(b.check(edge[i].f,edge[i].t)){
            continue;
        }
        b.merge(edge[i].f,edge[i].t);
        cnt++;
        ans+=edge[i].v;
        if(cnt==(n-1)){
            printf("%d\n",ans);
            return ;
        }
    }
}
int main()
{
    int n,m;
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        cin>>m;
        if(n==1){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].v);
        }
        sort(edge+1,edge+m+1);
        kru(n,m);
    }
    return 0;
}
