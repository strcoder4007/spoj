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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l, nm) fill_n(*l, sizeof l / sizeof **l, nm);
#define MOD 1000000007
using namespace std;

int t, n, m, h, w;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m>>h>>w;
    string sep = "";
    string grid = "";
    for(int i = 0; i <= (w+1)*m; i++)
        sep += "*";
    for(int i = 0; i < m; i++)
    {
        grid += "*";
        for(int j = 0; j < w; j++)
            grid += ".";
    }
    grid += "*";
    for(int i = 1; i <= n; i++)
    {
        cout<<sep<<endl;
        for(int j = 0; j < h; j++)
            cout<<grid<<endl;
    }
    cout<<sep<<endl;
}

return 0;}
