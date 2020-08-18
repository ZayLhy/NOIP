#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    double m,h;
    cin>>m>>h;
    double ans=m/(h*h);
    if(ans<18.5){
        cout<<"Underweight"<<endl;
        return 0;
    }
    if(ans>=18.5&&ans<24.0){
        cout<<"Normal"<<endl;
        return 0;
    }
    cout<<ans<<endl<<"Overweight"<<endl;
    return 0;
}