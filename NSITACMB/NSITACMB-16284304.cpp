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

int t, n, ary[15], sum;
vector<int>myvec;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

ary[0] = 1, ary[1] = 1;
for(int i = 2; i <= 10; i++)
    ary[i] = i*ary[i-1];
for(int mask = 0; mask < (1<<11); mask++)
{
    sum = 0;
    for(int i = 0; i <= 10; i++)
        if(mask & (1<<i))
            sum += ary[i];
    myvec.pb(sum);
}
sort(myvec.begin(), myvec.end());

cin>>t;
while(t--)
{
    cin>>n;
    int up = upper_bound(myvec.begin(), myvec.end(), n)-myvec.begin()-1;
    if(myvec[up] == n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

return 0;}
