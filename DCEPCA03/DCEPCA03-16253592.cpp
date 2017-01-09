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

long long t, num, found[10010];

long long phi(long long n)
{
    long long result = n;
    for (long long p=2; p*p<=n; ++p)
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

for(long long i = 1; i < 10001; i++)
	found[i] = phi(i);
for(long long i = 2; i < 10001; i++)
	found[i] += found[i-1];
cin>>t;
while(t--)
{
	cin>>num;
	cout<<found[num]*found[num]<<endl;
}


return 0;}
