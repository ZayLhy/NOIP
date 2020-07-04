#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Bcj{
    int fa[1000010];
    Bcj(){
        for(int i=0;i<1000010;i++){
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
}B;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char typ;
    for(int i=1,a,b;i<=m;i++){
        cin>>typ;
        scanf("%d%d",&a,&b);
        if(typ=='F'){
            B.merge(a,b);
        }
        if(typ=='E'){
            B.merge(b+n,a);
            B.merge(a+n,b);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(B.fa[i]==i){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}