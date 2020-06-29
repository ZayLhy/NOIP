#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
struct Node{
    double val;
    double tot;
    double tag;
}sgt[400010];
int ls(int x){
    return x<<1;
}
int rs(int x){
    return x<<1|1;
}
void update(int root){
    sgt[root].tot=sgt[ls(root)].tot+sgt[rs(root)].add;
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
    return ;
}
int main()
{
    return 0;
}