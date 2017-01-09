#include <set>
#include <list>
#include <map>
#include <stack>
#include <bitset>
#include <ctime>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <complex>
#include <iostream>
#include <algorithm>
#include <memory.h>

#define F first
#define endl "\n"
#define S second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pi 3.141592653589793
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
using namespace std;

long long t, ans, a, b, gcd;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>t;
while(t--)
{
    ans = 0;
    cin>>a>>b;
    ans = abs(a-b), a = abs(a), b = abs(b);
    cout<<ans/__gcd(a, b)<<endl;
}

return 0;}
