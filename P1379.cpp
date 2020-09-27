#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
unordered_map<long long,int> vis;
unordered_map<long long,int> step;
const long long goal = 123804765 ;
const int my[] = {0,0,1,-1};
const int mx[] = {1,-1,0,0};
struct Status{
    int matrix[4][4];
    int x;
    int y;
    Status(long long n){
        for(int i=3;i>=1;i--){
            for(int j=3;j>=1;j--){
                matrix[i][j]=n%10;
                n/=10;
                if(matrix[i][j]==0){
                    x=i;
                    y=j;
                }
            }
        }
    }
};
long long m2i(Status a){
    long long ans=0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            ans*=10;
            ans+=a.matrix[i][j];
        }
    }
    return ans;
}
void bfs(long long a){
    if(a==goal){
        printf("0\n");
        return ;
    }
    queue<long long> Q;
    Q.push(a);
    Q.push(goal);
    vis[a]=1;
    vis[goal]=2;
    step[a]=0;
    step[goal]=1;
    while(!Q.empty()){
        long long now=Q.front();
        long long next=now;
        Q.pop();
        Status nowm(now);
        for(int i=0;i<=3;i++){
            int nextx=nowm.x+mx[i];
            int nexty=nowm.y+my[i];
            if(nextx>3||nexty>3||nextx<1||nexty<1){
                continue;
            }
            swap(nowm.matrix[nowm.x][nowm.y],nowm.matrix[nextx][nexty]);
            next=m2i(nowm);
            if(vis.count(now)&&vis.count(next)){
                if(vis[now]==vis[next]){
                    swap(nowm.matrix[nowm.x][nowm.y],nowm.matrix[nextx][nexty]);
                    continue;
                }
                if(vis[now]+vis[next]==3){
                    cout<<step[now]+step[next]<<endl;
                    return ;
                }
            }
            step[next]=step[now]+1;
            vis[next]=vis[now];
            Q.push(next);
            swap(nowm.matrix[nowm.x][nowm.y],nowm.matrix[nextx][nexty]);
        }
    }
    return ;
}
int main()
{
    long long in;
    cin>>in;
    bfs(in);
    return 0;
}