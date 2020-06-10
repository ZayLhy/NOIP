#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int sum=0;
    int tmp;
    int maxn=-2147483648;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        if(sum<0){
            sum=0;
        }
        sum+=tmp;
        maxn=max(maxn,sum);
    }
    
    printf("%d\n",maxn);
    return 0;
}