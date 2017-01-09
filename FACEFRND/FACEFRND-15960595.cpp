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

int n, m, cnt, found[10000];
set<int>myset;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for(int i = 0; i < n; i++)
{
    int xs;
    cin>>xs;
    found[xs] = 1;
    cin>>m;
    for(int j = 0; j < m; j++)
    {
        int xd; cin>>xd;
        myset.insert(xd);
    }
}
for(set<int>::iterator ii = myset.begin(); ii != myset.end(); ii++)
    if(found[*ii] == 0)
        ++cnt;
cout<<cnt<<endl;

return 0;}
