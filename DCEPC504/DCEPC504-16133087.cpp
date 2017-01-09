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

long long t, n, k, cnt;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>k;
    cnt = 0;
    if(k == 1)
    {
        cout<<"Male"<<endl;
        continue;
    }
    else if(k == 2)
    {
        cout<<"Female"<<endl;
        continue;
    }
    else
    {
        --k;
        while(k > 1)
        {
            if(k&1)
                ++cnt;
            k >>= 1;
        }
    }
    if(cnt&1)
        cout<<"Male"<<endl;
    else
        cout<<"Female"<<endl;
}

return 0;}
