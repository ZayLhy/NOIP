#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int k;
int tri[2010][2010];
int tot[2010][2010];
void init(){
    tri[1][1]=tri[1][0]=tri[0][0]=1;
    for(int i=2;i<2010;i++){
        tri[i][0]=1;
    }
    for(int i=2;i<=2000;i++){
        for(int j=1;j<=i;j++){
            tri[i][j]=(tri[i-1][j]+tri[i-1][j-1])%k;
        }
    }
    for(int i=2;i<=2000;i++){
        for(int j=1;j<=i;j++){
            tot[i][j]=tot[i-1][j]+tot[i][j-1]-tot[i-1][j-1];
            if(!tri[i][j]){
                tot[i][j]++;
            }
        }
        tot[i][i+1]=tot[i][i];
    }
}
int main()
{
    int t;
    scanf("%d%d",&t,&k);
    init();
    for(int i=1,m,n;i<=t;i++){
        scanf("%d%d",&n,&m);
        m=min(m,n);
        printf("%d\n",tot[n][m]);
    }
    return 0;
}