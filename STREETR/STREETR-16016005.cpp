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

int n, gcd;
vector<int>myvec;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for(int i = 0; i < n; i++)
{
    int xs; cin>>xs;
    myvec.pb(xs);
}
sort(myvec.begin(), myvec.end());
gcd = myvec[1]-myvec[0];
for(int i = 2; i < n; i++)
    gcd = __gcd(gcd, myvec[i]-myvec[i-1]);
//cout<<myvec[0]<<" "<<myvec[n-1]<<" "<<gcd<<endl;
cout<<((myvec[n-1]-myvec[0])/gcd)-myvec.size()+1<<endl;

return 0;}
