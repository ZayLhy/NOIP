#include<cstdio>
#include<iostream>
using namespace std;
const int N=2e5+5,mo=10007;
struct cs{int to,nxt;}a[N*2];
int head[N],ll,v[N];
int n,ans,x,y,maxans;
void init(int x,int y){
    a[++ll].to=y;
    a[ll].nxt=head[x];
    head[x]=ll;
}
void work(int x){
    int sum=0,ma=0,m=0;
    for(int k=head[x];k;k=a[k].nxt){
        if(v[a[k].to]>ma){m=ma;    ma=v[a[k].to];}
        else if(v[a[k].to]>m)m=v[a[k].to];
        ans=(ans+sum*v[a[k].to])%mo;
        sum=(sum+v[a[k].to])%mo;
    }
    maxans=max(maxans,ma*m);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        init(x,y); init(y,x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)work(i);
    printf("%d %d",maxans,(ans*2)%mo);
}