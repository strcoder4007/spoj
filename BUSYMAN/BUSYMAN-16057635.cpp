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



long long t, n, cnt, last;
vector<pair<long long, long long> >myvec;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    myvec.clear();
    cnt = 0;
    for(int i = 0; i < n; i++)
    {
        long long x, y;
        cin>>x>>y;
        myvec.pb(mp(y, x));
    }
    last = -1;
    sort(myvec.begin(), myvec.end());
    for(int i = 0; i < myvec.size(); i++)
    {
        if(last <= myvec[i].S)
        {
            ++cnt;
            last = myvec[i].F;
        }
    }
    cout<<cnt<<endl;
}

return 0;}
