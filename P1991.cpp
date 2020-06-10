#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Bcj{
    int fa[250010];
    Bcj(){
        for(int i=0;i<250010;i++){
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
    double v;
    bool operator < (const Edge &a) const {
        return v<a.v;
    }
}edge[250010];
struct Pos{
    int x;
    int y;
}a[1010];
int p,s;
int cnt=1;
void kru(){
    int nodes=0;
    double minv=100000000.0;
    for(int i=1;i<=cnt;i++){
        if(b.check(edge[i].f,edge[i].t)){
            continue;
        }
        b.merge(edge[i].f,edge[i].t);
        nodes++;
        minv=edge[i].v;
        if(nodes>=(p-s)){
            printf("%.2f\n",minv);
            return ;
        }
    }
}
int main()
{
    scanf("%d%d",&s,&p);
    for(int i=1;i<=p;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        for(int j=1;j<i;j++){
            edge[cnt].f=i;
            edge[cnt].t=j;
            edge[cnt].v=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
//            printf("%.2f\n",edge[cnt].v);
            cnt++;
        }
    }
    sort(edge+1,edge+cnt+1);
    kru();
    return 0;
}