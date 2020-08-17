#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int x[100010];
int y[100010];
int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<int> a;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &y[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            
        }
    }
    return 0;
}