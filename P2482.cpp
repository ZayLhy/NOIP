#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int n, m;
int mian;
bool endflag = false;
string Repo[2010];
struct P2842
{
    int sf; //身份
    string card;
    int cardcount = 0;
    bool tz = false;   //跳忠
    bool tf = false;   //反
    int enermy[10];    //敌人
    int mate[10];      //同伴
    bool ln = false;   //诸葛村妇
    bool kill = false; //是否用杀
    bool dead = false;
    void init()
    {
        kill = false; //标记杀可用
    }
    void mpo()
    { //origin_card
        for (int i = 0; i < 10; i++)
        {
            enermy[i] = mate[i] = 0;
        }
        string tmp;
        cin >> tmp;
        if (tmp == "MP")
        {
            sf = 1;
        }
        if (tmp == "ZP")
        {
            sf = 2;
        }
        if (tmp == "FP")
        {
            sf = 3;
        }
        tmp.clear();
        for (int i = 1; i <= 4; i++)
        {
            tmp.clear();
            cin >> tmp;
            card += tmp;
            card += ' ';
            cardcount++;
        }
    }
    void printinfo()
    { //printcard_fordebug
        cout << sf << " ";
        cout << card << endl;
    }
    void mp()
    {
    }
    void cp()
    {
    }
} pigs[15];
void cpzu(int x)
{
}
void cpzo(int x)
{
}
void cpf(int x)
{
}
void kill(int x)
{
}
bool run(int x)
{
}
void peach(int x)
{
}
void south(int x)
{
}
void arrow()
{
}
void non(int x)
{
}
void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        pigs[i].mpo();
        if (pigs[i].sf == 1)
        {
            mian = i;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> Repo[i];
    }
}
void play()
{
    int nowpig = 1;
    while (1)
    {
        if (endflag)
        {
            return;
        }
        if (nowpig > n)
        {
            nowpig = 1;
        }
        pigs[nowpig].mp();
        pigs[nowpig].cp();
    }
}
void end()
{
}
int main()
{
    init();
    play();
    end();
    return 0;
}