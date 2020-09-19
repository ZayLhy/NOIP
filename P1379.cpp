#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<pair>
using namespace std;
unordered_map<int,int> m,ans;
const long long goal = 123804765;
const int mx[] = {1,-1,0,0};
const int my[] = {0,0,1,-1};
void transform(int* a,long long status){
    for(int i=3;i>=1;i--){
        for(int j=3;j>=1;j--){
            a[i][j]=status%10;
            status/=10;
            if(a[i][j]==0){
                pair<int,int> pos = make_pair(i,j);
            }
        }
    }
    return pos;
}
void bfs(long long status){
    queue<long long> Q;
    if(status==goal){
        printf("0\n");
        return ;
    }
    int tmp[5][5];
    Q.push(status);
    Q.push(goal);
    while(!Q.empty()){

    }
}
int main()
{
    long long in;
    cin>>in;
    bfs(in);
    return 0;
}