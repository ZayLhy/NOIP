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
};
int main(){
    int n,m,x,y,ans;
    for(int i=1;i;i){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        scanf("%d",&m);
        Bcj b;
        ans=0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            b.merge(x,y);
        }
        for(int i=1;i<=n;i++){
            if(b.fa[i]==i){
                ans++;
            }
        }
        printf("%d\n",ans-1);
    }
    return 0;
}