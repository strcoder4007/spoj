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

int t, n, cnt, a, depth, mxdepth, mxc, pos;
string st;

void recur(int depth)
{
	if(st[pos] == '1')
        cnt++;
	if(depth > mxdepth)
		mxdepth = depth, mxc = cnt;
	if(st[pos++] == '1')
		recur(depth+1), recur(depth+1);
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n)
{
    cnt = 0, mxdepth = 0, mxc = 0, pos = 0;
    cin>>st;
    recur(1);
    cout<<mxc<<endl;
}

return 0;}
