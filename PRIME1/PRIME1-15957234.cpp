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

int t, l, r;
set<int>myset;
bool ary[32001];

void esieve()
{
    for(int i = 2; i <= 32000; i++)
    {
        int ii = 2;
        while(i*ii <= 32000)
        {
            ary[i*ii] = true;
            ++ii;
        }
    }
    for(int i = 2; i <= 32000; i++)
        if(ary[i] == false)
            myset.insert(i);
}


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

esieve();
cin>>t;
while(t--)
{
    cin>>l>>r;
    if(l == 1)
        ++l;
    int cap = sqrt(r) + 1;
    set<int> notprime;
    notprime.clear();

    set<int>::iterator p;
    for (p = myset.begin(); p != myset.end(); p++)
    {
        if (*p >= cap)
            break;
        int start;
        if (*p >= l)
            start = (*p)*2;
        else
            start = l + ((*p - l % *p) % *p);
        for (int j = start; j <= r; j += *p)
            notprime.insert(j);
    }
    for (int i = l; i <= r; i++)
        if (notprime.count(i) == 0)
            cout << i << endl;
    cout<<endl;
}

return 0;}
