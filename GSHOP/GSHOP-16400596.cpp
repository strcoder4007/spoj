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


long long ans, t, n, k, xs, minn, mini;
vector<long long>myvec;
bool pos, neg, zero;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>t;
while(t--)
{
    cin>>n>>k;
    if(n == 0)
    {
        cout<<0<<endl;
        continue;
    }
    ans = 0, myvec.clear(), pos = false, neg = false, zero = false, minn = 1e9, mini = 1e9;
    for(int i = 0; i < n; i++)
    {
        cin>>xs;
        if(xs > 0)
            ans += xs, pos = true, minn = min(minn, xs);
        else if(xs < 0)
            myvec.pb(xs), neg = true;
        else
            zero = true;
    }
    sort(myvec.begin(), myvec.end());
    if(neg)
        mini = -(myvec[myvec.size()-1]);
    for(int i = 0; i < myvec.size(); i++)
    {
        if(k > 0)
            myvec[i] *= (-1), --k;
        ans += myvec[i];
    }
    if(k&1 && !zero)
    {
        if(pos && neg)
            ans -= 2*min(minn, mini);
        if(pos && !neg)
            ans -= 2*minn;
        if(!pos && neg)
            ans -= 2*mini;
    }
    cout<<ans<<endl;
}

return 0;}
