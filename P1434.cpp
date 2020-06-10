#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int a[210][210];
int dp[210][210];
const int mx[4]={0,1,0,-1};
const int my[4]={1,0,-1,0};
int r,c;
int dfs(int x,int y){
    if(dp[x][y]){
        return dp[x][y];
    }
    int ans=1;
    for(int i=0;i<4;i++){
        int nx=mx[i]+x;
        int ny=my[i]+y;
        if(nx>0&&nx<=r&&ny>0&&ny<=c&&a[x][y]>a[nx][ny]){
            ans=max(ans,dfs(nx,ny)+1);
        }
    }
    dp[x][y]=ans;
    return ans;
}
int main(){
//    freopen("a.in","r",stdin);
    scanf("%d%d",&r,&c);
    int highest=0,x,y;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            highest=max(highest,a[i][j]);
            if(highest==a[i][j]){
                x=i;
                y=j;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    printf("%d\n",ans);
    return 0;
}