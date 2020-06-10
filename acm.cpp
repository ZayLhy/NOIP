#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int SZ = 10010;
const int mod = 10007;

int dp[110][SZ];

int ch[SZ][30],sz = 0,val[SZ];

void insert(char s[])
{
    int p = 0;
    int l = strlen(s);
    for(int i = 0;i < l;i ++)
    {
        int c = s[i] - 'A' + 1;
        if(!ch[p][c]) ch[p][c] = ++ sz;
        p = ch[p][c];
    }
    val[p] ++;
}

queue<int> q;
int fail[SZ];

void build_trieg()
{
    fail[0] = 0;
    for(int i = 1;i <= 26;i ++)
    {
        int u = ch[0][i];
        if(u) { q.push(u); fail[u] = 0; }
    }
    while(q.size())
    {
        int f = q.front(); q.pop();
        val[f] += val[fail[f]];
        for(int c = 1;c <= 26;c ++)
        {
            int u = ch[f][c];
            if(!u) { ch[f][c] = ch[fail[f]][c]; continue; }
            q.push(u);
            fail[u] = ch[fail[f]][c];
        }
    }
}


char s[SZ];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++)
    {
        scanf("%s",s);
        insert(s);
    }
    build_trieg();

    dp[0][0] = 1;
    for(int len = 1;len <= m;len ++)
    {
        for(int u = 0;u <= sz;u ++)
        {
            if(val[u]) continue;
            for(int c = 1;c <= 26;c ++)
            {
                int v = ch[u][c];
                dp[len][v] = (dp[len][v] + dp[len - 1][u]) % mod;
            }
        }
    }
    int ans = 0,tot = 1;
    for(int i = 1;i <= m;i ++) tot = tot * 26 % mod;
    for(int i = 0;i <= sz;i ++)
        if(!val[i]) ans = (ans + dp[m][i]) % mod;
    printf("%d",(tot - ans + mod) % mod);
    return 0;
}