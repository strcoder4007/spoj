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
#include <stdlib.h>
#include <climits>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 10000007
using namespace std;

int t, n, q, m, start, dest, k, xs;
vector<int>myvec, newvec, adj[1010];

void dfs1(int x)
{
    if(x == 1)
    {
        myvec.pb(x);
        return;
    }
    for(int i = 0; i < adj[x].size(); i++)
        dfs1(adj[x][i]);
    myvec.pb(x);
}
void dfs2(int x)
{
    if(x == 1)
    {
        newvec.pb(x);
        return;
    }
    for(int i = 0; i < adj[x].size(); i++)
        dfs2(adj[x][i]);
    newvec.pb(x);
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    ++k;
    cin>>n;
    for(int i = 1; i <= n; i++)
        adj[i].clear();
    for(int i = 1; i <= n; i++)
    {
        cin>>m;
        while(m-- && cin>>xs)
            adj[xs].pb(i);
    }
    cin>>q;
    cout<<"Case "<<k<<":"<<endl;
    while(q--)
    {
        cin>>start>>dest;
        myvec.clear();
        newvec.clear();
        dfs1(start);
        dfs2(dest);
        int i;
        for(i = 0; i < min(myvec.size(), newvec.size()); i++)
            if(myvec[i] != newvec[i])
                break;
        cout<<myvec[i-1]<<endl;
    }
}

return 0;}
