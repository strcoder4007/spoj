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

int a, k;
vector<int>myvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>a && a != EOF)
{
    ++k;
    myvec.clear();
    myvec.pb(a);
    for(int i = 0; i < 3; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
    }
    sort(myvec.begin(), myvec.end(), greater<int>());
    cout<<"Case "<<k<<": "<<myvec[0]+myvec[1]<<endl;
}

return 0;}
