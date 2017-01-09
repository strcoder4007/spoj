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

int t, n, m;
vector<int>myvec, newvec;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    myvec.clear(), newvec.clear();
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
    }
    for(int i = 0; i < m; i++)
    {
        int xs; cin>>xs;
        newvec.pb(xs);
    }
    sort(myvec.begin(), myvec.end());
    sort(newvec.begin(), newvec.end());
    int i = 0, j = 0;
    while(i != n && j != m)
    {
        //cout<<i<<" "<<j<<endl;
        if(myvec[i] < newvec[j])
            ++i;
        else
            ++j;
    }
    if(i == n)
        cout<<"MechaGodzilla"<<endl;
    else if(j == m)
        cout<<"Godzilla"<<endl;
}


return 0;}
