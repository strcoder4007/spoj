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

int t, n, found[2010];
bool done;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    done = false;
    memset(found, 0, sizeof found);
    cin>>n;
    for(int i = 0;  i < n; i++)
    {
        int xs; cin>>xs;
        if(xs < 0)
            xs = -xs, xs += 1000;
        ++found[xs];
    }
    for(int i = 0;  i < 2001; i++)
    {
        if(found[i] > n/2)
        {
            cout<<"YES "<<i<<endl;
            done = true;
            break;
        }
    }
    if(!done)
        cout<<"NO"<<endl;

}

return 0;}
