#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
string mid,front;
void back(string mid,string front){
    if(mid.size()>0){
        int pos = mid.find(front[0]);
        char root = front[0];
        front.erase(front.begin());
        back();
        back();
        cout<<root;
    }
    return ;
}
int main()
{
    cin>>mid>>front;
    back(mid,front);
    return 0;
}