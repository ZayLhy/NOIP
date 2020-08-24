#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long a=0;
long long cnta=0;
long long b=0;
long long cntb=0;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        if(i%k==0){
            a+=i;
            cnta++;
            continue;
        }
        b+=i;
        cntb++;
    }
    printf("%.1f %.1f\n",(double)a/(double)cnta,(double)b/(double)cntb);
    return 0;
}