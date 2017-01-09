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

int t, n;
vector<int>myvec, newvec;
bool error;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    myvec.clear();
    newvec.clear();
    error = false;
    for(int i = 0; i < n; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
        newvec.pb(xs);
    }
    next_permutation(myvec.begin(), myvec.end());
    error = lexicographical_compare(myvec.begin(), myvec.end(), newvec.begin(), newvec.end());
    if(myvec == newvec)
        error = 1;
    if(error)
        cout<<-1<<endl;
    else
    {
        for(int i = 0; i < myvec.size(); i++)
            cout<<myvec[i];
        cout<<endl;
    }
}

return 0;}
