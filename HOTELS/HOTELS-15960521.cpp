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

int n, m, ary[300030], i;
long long ans, sum;
bool inwhile;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for(int xs = 0; xs < n; xs++)
    cin>>ary[xs];

i = -1;
while(sum < m)
{
    ++i;
    if(sum+ary[i] <= m)
        sum += ary[i];
    else
    {
        --i;
        break;
    }
}
while(sum > m)
{
    sum -= ary[i];
    --i;
}

ans = sum;
//cout<<i<<" "<<sum<<endl;
int j = 0;
while(j < n-1 && i < n-1)
{
    ++i;
    sum += ary[i];
    while(sum > m)
    {
        sum -= ary[j];
        ++j;
    }
    //cout<<sum<<endl;
    ans = max(ans, sum);
}
cout<<ans<<endl;

return 0;}
