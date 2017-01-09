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

int n;
vector<string>myvec;
long long sum, multi, dots, dash;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n && n != 0)
{
    sum = 0;
    myvec.clear();
    for(int i = 0; i <= n; i++)
    {
        string xs;
        getline(cin, xs);
        myvec.pb(xs);
    }
    reverse(myvec.begin(), myvec.end());
    multi = 1;
    for(int i = 0; i < n; i++)
    {
        if(myvec[i] != "S")
        {
            dots = 0;
            dash = 0;
            for(int j = 0; j < myvec[i].size(); j++)
            {
                if(myvec[i][j] == '.')
                    ++dots;
                else if(myvec[i][j] == '-')
                    ++dash;
            }
            sum += (5*dash+dots)*multi;
        }
        if(i == 1)
            multi = 360;
        else
            multi *= 20;
    }
    cout<<sum<<endl;
}

return 0;}
