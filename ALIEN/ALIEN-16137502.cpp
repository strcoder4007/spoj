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
#define int long long

int n, m, ary[100010], i;
int ans, sum, t, p, q, idx;
bool inwhile;

main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    sum = 0, ans = 0;
    for(int xs = 0; xs < n; xs++)
        cin>>ary[xs];
    ans = 1e9;
    p = 0, q = 0, sum = ary[0], idx = 0;
    while(p < n-1 && q < n)
    {
        if(sum <= m)
        {
            if(q-p+1> idx)
				{
					idx=q-p+1;
					ans = sum;
				}
				else
					if(q-p+1==idx)
						ans=min(ans,sum);
        }
        if(sum < m)
            q++, sum += ary[q];
        else
            p++, sum -= ary[p-1];
    }
    cout<<ans<<" "<<idx<<endl;

}

}
