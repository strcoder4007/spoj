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

long long t, n, sum, idx;
vector<long long >myvec;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
int k = t;
while(t--)
{
    cin>>n;
    sum = 0;
    myvec.clear();
    idx = -1;
    for(int i = 0; i < n; i++)
    {
        int xs; cin>>xs;
        myvec.pb(xs);
    }
    for(int i = n-1; i+1; i--)
        if(myvec[i] <= 0)
        {
            idx = i;
            break;
        }
    if(idx == -1)
    {
        cout<<"Scenario #"<<k-t<<": "<<1<<endl;
        continue;
    }
    sum = 1-myvec[idx];
    for(int i = idx-1; i+1; i--)
    {
        sum -= myvec[i];
        if(sum == 0)
            ++sum;
        else if(sum < 0)
            sum = 1;
    }
    cout<<"Scenario #"<<k-t<<": "<<sum<<endl;
}

return 0;}
