#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct P2278
{
    int id;
    int start;
    int runtime;
    int pri;
    bool operator < (const P2278 &a) const {
        if(start==a.start){
            return pri<a.pri;
        }
        return start>a.start;
    }  
};
priority_queue<P2278> Q;
int main()
{
    return 0;
}