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

int t, n, x, y, found[100010];


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>t;
while(t--)
{
    cin>>n>>x>>y;
    memset(found, 0, sizeof(found));
    for(int i = x; i < n; i+=x)
        if(i%x == 0)
            found[i] ^= 1;
    for(int i = y; i < n; i+=y)
        if(i%x == 0)
            found[i] ^= 1;
    for(int i = x; i < n; i++)
        if(found[i] == 1)
            cout<<i<<" ";
    cout<<endl;
}

return 0;}
