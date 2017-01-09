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
#define int long long

int n;
vector<int>myvec, newvec;
long long sum;

main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n && n != 0)
{
    sum = 0;
    myvec.clear();
    newvec.clear();
for(int i = 0; i < n; i++)
{
    int xs; cin>>xs;
    myvec.pb(xs);
}
for(int i = 0; i < n; i++)
{
    int xs;cin>>xs;
    newvec.pb(xs);
}
sort(myvec.begin(), myvec.end());
sort(newvec.begin(), newvec.end(), greater<int>());
for(int i = 0; i < n; i++)
    sum += myvec[i]*newvec[i];
cout<<sum<<endl;
}

}
