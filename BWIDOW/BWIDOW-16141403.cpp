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

int t, n;
vector<pair<pair<int, int> , int> > myvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    myvec.clear();
    for(int i = 0; i < n; i++)
    {
        int x, y; cin>>x>>y;
        myvec.pb(mp(mp(y, x), i+1));
    }
    sort(myvec.begin(), myvec.end());
    if(n == 1)
    {
        cout<<1<<endl;
        continue;
    }
    if(myvec[n-1].F.S > myvec[n-2].F.F)
        cout<<myvec[n-1].S<<endl;
    else
        cout<<-1<<endl;
}

return 0;}
