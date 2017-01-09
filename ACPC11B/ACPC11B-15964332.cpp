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

int n, ans, m, calc, low;
vector<int>myvec, newvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
while(n--)
{
    myvec.clear();
    newvec.clear();
    ans = 1e9;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
    }
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        int xs; cin>>xs;
        newvec.pb(xs);
    }
    sort(myvec.begin(), myvec.end());
    for(int i = 0; i < newvec.size(); i++)
    {
        low = lower_bound(myvec.begin(), myvec.end(), newvec[i])-myvec.begin();
        if(low == myvec.size())
        {
            --low;
            calc = abs(newvec[i] - myvec[low]);
        }
        else if(low != 0)
            calc = min(abs(newvec[i]-myvec[low]), abs(newvec[i]-myvec[low-1]));
        else
            calc = abs(newvec[i]-myvec[low]);

        //cout<<calc<<" "<<low<<" "<<newvec[i]<<" "<<myvec[low]<<endl;
        ans = min(ans, calc);
    }
    cout<<ans<<endl;
}

return 0;}
