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
#include <limits.h>
#include <stdlib.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 1000000007
using namespace std;

long long t, n, m, gcd;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    if(n&1)
    {
        if(n == m)
            cout<<"R"<<endl;
        else if(n < m)
            cout<<"R"<<endl;
        else
        {
            if(m &1)
                cout<<"D"<<endl;
            else
                cout<<"U"<<endl;
        }
    }
    else
    {
        if(n == m)
            cout<<"L"<<endl;
        else if(n < m)
            cout<<"L"<<endl;
        else
        {
            if(m &1)
                cout<<"D"<<endl;
            else
                cout<<"U"<<endl;
        }
    }
}

return 0;}
