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

int t, n, m;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    string sep = "";
    string grid = "";
    for(int i = 0; i <= 3*m; i++)
        sep += "*";
    for(int i = 0; i < m; i++)
        grid += "*..";
    grid += "*";
    for(int i = 1; i <= n; i++)
    {
        cout<<sep<<endl;
        cout<<grid<<endl<<grid<<endl;
    }
    cout<<sep<<endl;
}

return 0;}
