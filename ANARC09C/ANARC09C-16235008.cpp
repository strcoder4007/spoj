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

int a, b, cnt, sum, found[1000010], ary[1000010], k;
map<int, int>mymap, newmap;
vector<int>myvec;

void esieve(int num)
{
    for(int i = 2; i < num; i++)
        if(ary[i] == false)
        {
            int ii = 2;
            myvec.pb(i);
            while(i*ii <= num)
                ary[i*ii] = true, ++ii;
        }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

esieve(1000007);
while(cin>>a && a)
{
    ++k;
    cin>>b;
    cnt = 0, sum = 0, mymap.clear(), newmap.clear();
    memset(found, 0, sizeof(found));
    for(int i = 0; i < myvec.size(); i++)
    {
        int fst = 0, sec = 0;
        if((a%myvec[i] == 0 && a != 1)|| (b%myvec[i] == 0 && b != 1))
            ++found[myvec[i]];
        while(a%myvec[i] == 0 && a != 1)
            a /= myvec[i], ++fst;
        while(b%myvec[i] == 0 && b != 1)
            b /= myvec[i], ++sec;
        sum += abs(fst-sec);
    }
    for(int i = 1; i <= 1000000; i++)
        if(found[i] != 0)
            ++cnt;
    cout<<k<<". "<<cnt<<":"<<sum<<endl;
}

return 0;}
