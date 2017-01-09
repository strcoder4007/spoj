#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <list>
#include <ctime>
#include <memory.h>
#include <bitset>
#include <climits>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l, nm) fill_n(*l, sizeof l / sizeof **l, nm);
#define MOD 1000000007
using namespace std;

int t, x, o;
char ary[5][5];
bool flag, flag2;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    x = 0, o = 0;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
        {
            cin>>ary[i][j];
            if(ary[i][j] == 'X')
                ++x;
            else if(ary[i][j] == 'O')
                ++o;
        }
        flag = false, flag2 = false;
    if(ary[1][1] == 'X' && ary[1][2] == 'X' && ary[1][3] == 'X')
        flag = true;
    else if(ary[2][1] == 'X' && ary[2][2] == 'X' && ary[2][3] == 'X')
        flag = true;
    else if(ary[3][1] == 'X' && ary[3][2] == 'X' && ary[3][3] == 'X')
        flag = true;
    else if(ary[1][1] == 'X' && ary[2][2] == 'X' && ary[3][3] == 'X')
        flag = true;
    else if(ary[3][1] == 'X' && ary[2][2] == 'X' && ary[1][3] == 'X')
        flag = true;
    else if(ary[1][1] == 'X' && ary[2][1] == 'X' && ary[3][1] == 'X')
        flag = true;
    else if(ary[1][2] == 'X' && ary[2][2] == 'X' && ary[3][2] == 'X')
        flag = true;
    else if(ary[1][3] == 'X' && ary[2][3] == 'X' && ary[3][3] == 'X')
        flag = true;

        if(ary[1][1] == 'O' && ary[1][2] == 'O' && ary[1][3] == 'O')
            flag2 = true;
        else if(ary[2][1] == 'O' && ary[2][2] == 'O' && ary[2][3] == 'O')
            flag2 = true;
        else if(ary[3][1] == 'O' && ary[3][2] == 'O' && ary[3][3] == 'O')
            flag2 = true;
        else if(ary[1][1] == 'O' && ary[2][2] == 'O' && ary[3][3] == 'O')
            flag2 = true;
        else if(ary[3][1] == 'O' && ary[2][2] == 'O' && ary[1][3] == 'O')
            flag2 = true;
        else if(ary[1][1] == 'O' && ary[2][1] == 'O' && ary[3][1] == 'O')
            flag2 = true;
        else if(ary[1][2] == 'O' && ary[2][2] == 'O' && ary[3][2] == 'O')
            flag2 = true;
        else if(ary[1][3] == 'O' && ary[2][3] == 'O' && ary[3][3] == 'O')
            flag2 = true;
    if(flag && flag2)
        cout<<"no"<<endl;
    else if(flag && !flag2 && x-o == 1)
        cout<<"yes"<<endl;
    else if(!flag && flag2 && x-o == 0)
        cout<<"yes"<<endl;
    else if(!flag && !flag2)
    {
        if(x-o == 0 || x-o == 1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    else
        cout<<"no"<<endl;
}

return 0;}
