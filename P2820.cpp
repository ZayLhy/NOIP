#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Bcj{
    int fa[100010];
    Bcj(){
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
int n,k,w=0;
void kru(){
    int cnt=0,ans=0;
    for(int i=1;i<=k;i++){
        if(b.check(edge[i].f,edge[i].t)){
            continue;
        }
        cnt++;
        b.merge(edge[i].f,edge[i].t);
        w-=edge[i].v;
        if(cnt==(n-1)){
            printf("%d\n",w);
            return ;
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].v);
        w+=edge[i].v;
    }
//    printf("%d\n",w);
    sort(edge+1,edge+k+1);
    kru();
    return 0;
}