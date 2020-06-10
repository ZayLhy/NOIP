#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge{
    int f;
    int t;
}a[12010];
int head[12010],nxt[12010],tot;
int happy[12010];
int oud[12010];
int dp[12010][2];
void add(int f,int t){
    a[++tot]=(Edge){f,t};
    nxt[tot]=head[f];
    head[f]=tot;
    return ;
}
int n;
void dfs(int now){
    dp[now][1]+=happy[now];
    for(int i=head[now];i;i=nxt[i]){
        int Next=a[i].t;
        dfs(Next);
        dp[now][0]+=max(dp[Next][0],dp[Next][1]);
        dp[now][1]+=dp[Next][0];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&happy[i]);
    }
    for(int i=1,f,t;i<=n;i++){
        scanf("%d%d",&f,&t);
        if(f==t&&t==0){
            break;
        }
    //    add(f,t);
        add(t,f);
        oud[f]++;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(oud[i]==0){
            dfs(i);
            root=i;
        }
    }
    printf("%d\n",max(dp[root][0],dp[root][1]));
    return 0;
}