#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const double eps = 1e-8;

struct Vector
{
    double a;
    double b;
    double c;
} mat[510] /*原料*/, goal[510] /*成品*/;
int m, n;
int f[510][510];

Vector add(Vector a, Vector b)
{
    return (Vector){a.a - b.a, a.b - b.b};
}

double xmul(Vector a, Vector b)
{
    return a.a * b.b - a.b * b.a;
}

double dotmul(Vector a, Vector b)
{
    return a.a * b.a + a.b * b.b;
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        cin >> mat[i].a >> mat[i].b >> mat[i].c;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> goal[i].a >> goal[i].b >> goal[i].c;
    }
    memeset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool flag = false;
            for (int k = 1; k <= m; k++)
            {
                
            }
        }
    }
    return 0;
}