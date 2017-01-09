
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
#define MOD 10000007
using namespace std;
#define int long long

int test, n, sum, maxx, found[10000010];
set<int>myset;

main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>test;
while(test--)
{
    cin>>n;
    maxx = -1;
    myset.clear();
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        myset.insert(x);
        myset.insert(y);
        found[x] = 1, found[y] = -1;
    }
    for(set<int>::iterator ii = myset.begin(); ii != myset.end(); ii++)
    {
        sum += found[*ii];
        maxx = max(maxx, sum);
        found[*ii] = 0;
    }
    cout<<maxx<<endl;
}


}
