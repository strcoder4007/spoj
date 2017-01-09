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

int n, k, found[1000010], maxx, ary[1000010];
vector<int>myvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for(int i = 0; i < n; i++)
    cin>>ary[i];
cin>>k;
maxx = -1;
for(int i = 0; i < k; i++)
{
    maxx = max(maxx, ary[i]);
    ++found[ary[i]];
}
myvec.pb(maxx);
int i = 0;
for(int j = k; j < n; j++)
{
    ++found[ary[j]];
    --found[ary[i]];
    ++i;
    if(maxx == ary[i-1])
    {
        if(found[ary[i-1]] == 0)
        {
            maxx = -1;
            for(int xs = i; xs <= j; xs++)
                maxx = max(maxx, ary[xs]);
        }
    }//main if
    else
    {
        if(maxx < ary[j])
            maxx = ary[j];
    }
    myvec.pb(maxx);
}
for(int i = 0; i < myvec.size(); i++)
    cout<<myvec[i]<<" ";
cout<<endl;

return 0;}
