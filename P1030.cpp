#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
void front(string mid,string back){
    if(mid.size()>0){
        cout<<back[back.size()-1];
        int pos = mid.find(back[back.size()-1]);
        front(mid.substr(0,pos),back.substr(0,pos));
        front(mid.substr(pos+1),back.substr(pos,mid.size()-pos-1));
    }
}
int main()
{
    string mid,back;
    cin>>mid>>back;
    front(mid,back);
    return 0;
}