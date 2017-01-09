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

vector<int>myvec;
int t, n, m, cnt, found[100010];

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    myvec.clear();
    memset(found, 0, sizeof found);
    cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
    }
    sort(myvec.begin(), myvec.end());
    for(int i = 0; i < n; i++)
    {
        if(found[i] == 0)
        {
            int low = upper_bound(myvec.begin(), myvec.end(), m-myvec[i])-myvec.begin()-1;
            if(myvec[low] == m-myvec[i] && found[low] == 0 && low != i)
                ++cnt, found[low] = 1, found[i] = 1;
        }
    }
    cout<<cnt<<endl;
}

return 0;}
