#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
long long isprime(long long n){
    priority_queue<long long> Q;
    Q.push(1);
    for(int i=2;(i*i)<=n;i++){
        if(n%i==0){
            Q.push(n/i);
        }
    }
    return Q.top();
}
int main()
{
    int t;
    scanf("%d",&t);
    long long n;
    for(int i=1;i<=t;i++){
        cin>>n;
        cout<<isprime(n)<<" "<<(n-isprime(n))<<endl;
    }
    return 0;
}