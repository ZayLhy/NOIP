#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
    srand(time(NULL));
    for(int i=1;i<=100000000;i++){
        a.push_back(rand()*rand());
        srand(rand());
    }
    sort(a.begin(),a.end());
    return 0;
}