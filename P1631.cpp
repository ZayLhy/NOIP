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
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a.size() < n)
            {
                a.push((x[i] + y[j]));
                continue;
            }
            if ((x[i] + y[j]) < (a.top()))
            {
                a.pop();
                a.push((x[i] + y[j]));
                continue;
            }
            break;
        }
    }
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        b.push_back(a.top());
        a.pop();
    }
    reverse(b.begin(), b.end());
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", b[i - 1]);
    }
    cout << endl;
    return 0;
}