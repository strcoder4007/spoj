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
#define MOD 1000000007
using namespace std;

int t, a, b, cnt;
vector<int>myvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    myvec.clear();
    cnt = 0;
    cin>>a>>b;
    int gcd = __gcd(a, b);
    if(a == 0 || b == 0)
    {
        cout<<0<<endl;
        continue;
    }
    for(int i = 1; i*i <= gcd; i++)
    {
        if(gcd%i == 0)
        {
            if(i*i == gcd)
                myvec.pb(i);
            else
                myvec.pb(i), myvec.pb(gcd/i);
        }
    }
    for(int i = 1; i*i <= gcd; i++)
    {
        if(gcd%i == 0)
        {
            if(i*i == gcd)
                myvec.pb(i);
            else
                myvec.pb(i), myvec.pb(gcd/i);
        }
    }
    sort(myvec.begin(), myvec.end());
    for(int i = 0; i < myvec.size()-1; i++)
    {
        if(myvec[i] == myvec[i+1])
            ++cnt, ++i;
    }
    cout<<cnt<<endl;

}

return 0;}
