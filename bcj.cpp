#include<cstdio>
using namespace std;
struct Bcj{
    int fa[20010];
    Bcj(){for(int i=0;i<20010;i++)fa[i]=i;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    bool check(int x,int y){return find(x)==find(y);}
    void merge(int x,int y){fa[find(x)]=find(y);}
}b;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,typ;i<=m;i++){
        scanf("%d%d%d",&typ,&x,&y);
        if(typ==1){
            b.merge(x,y);
        }
        if(typ==2){
            if(b.check(x,y)){
                printf("Y\n");
                continue;
            }
            printf("N\n");
        }
    }
    return 0;
}