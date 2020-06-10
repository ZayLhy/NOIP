#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int sum[2][100005];
int ans;
int main(){
    string a;
    cin>>a;
    int n=a.length();
    for(int i=1;i<=n;i++){
        if(a[i-1]=='0'){
            sum[0][i]++;
        }
        if(a[i-1]=='1'){
            sum[1][i]++;
        }
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
    }
    int nowans=0;
    int l=1,r=l;
    while(1){
        if(r==n){
            break;
        }
        nowans=(sum[0][r]-sum[0][l-1])-(sum[1][r]-sum[1][l-1]);
        if(nowans<=0){
            l=r;
            r++;
            continue;
        }
        r++;
        ans=max(ans,nowans);
    }
    if(ans==0&&sum[0][n]==0){
        ans=-1;
    }
    if(sum[1][n]==0){
        ans=n;
    }
    printf("%d\n",ans);
    //putchar('\n');
    return 0;
}