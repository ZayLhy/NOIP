#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a[5];
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    sort(a+1,a+4);
    if(a[1]+a[2]<=a[3]){
        cout<<"Not triangle"<<endl;
        return 0;
    }
    if((a[1]*a[1]+(a[2]*a[2]))==(a[3]*a[3])){
        cout<<"Right triangle"<<endl;
    }
    if((a[1]*a[1]+(a[2]*a[2]))>(a[3]*a[3])){
        cout<<"Acute triangle"<<endl;
    }
    if((a[1]*a[1]+(a[2]*a[2]))<(a[3]*a[3])){
        cout<<"Obtuse triangle"<<endl;
    }
    if(a[1]==a[2]||a[2]==a[3]){
        cout<<"Isosceles triangle"<<endl;
    }
    if(a[1]==a[2]&&a[2]==a[3]){
        cout<<"Equilateral triangle"<<endl;
    }
    return 0;
}