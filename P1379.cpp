#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
unordered_map<int,int> a;
const long long goal = 123804765;
const int mx[] = {1,-1,0,0};
const int my[] = {0,0,1,-1};
void bfs(long long status){
    if(status==goal){
        printf("0\n");
        return ;
    }
    
}
int main()
{
    long long in;
    cin>>in;
    bfs(in);
    return 0;
}