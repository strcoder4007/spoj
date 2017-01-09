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

int n, k;
long long one, two, three, four, ans;

long long biexpo(long long base,long long power,long long M)
{
    if(power==0)
       return 1;
    if(power==1)
    return base;
    long long halfn = biexpo(base,power/2,M);
    if(power%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


while(cin>>n && n != 0)
{
    cin>>k;
    one = (2*biexpo(n-1, k, MOD))%MOD;
    two = (biexpo(n, k, MOD))%MOD;
    three = (2*biexpo(n-1, n-1, MOD))%MOD;
    four = (biexpo(n, n, MOD))%MOD;
    ans = (one+two+three+four)%MOD;
    cout<<ans<<endl;
}

return 0;}
