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

long long sum, found[500010], t, n;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

for(int i = 2; i <= 500000; i++)
{
    sum = 0;
    for(int j = 1; j*j <= i; j++)
        if(j*j == i)
            sum += j;
        else if(i%j == 0)
            sum += j+i/j;
    found[i] = sum;
}
cin>>t;
while(t--)
{
    cin>>n;
    if(n == 1)
        cout<<0<<endl;
    else
        cout<<found[n]-n<<endl;
}

return 0;}
