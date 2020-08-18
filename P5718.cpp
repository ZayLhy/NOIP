#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
priority_queue<int> q;
int main()
{
    int n;
    cin>>n;
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
        q.push(-tmp);
    }
    printf("%d\n",-q.top());
    return 0;
}