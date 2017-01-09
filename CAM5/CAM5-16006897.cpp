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
#define MOD 10000007
using namespace std;

int t, cnt, visited[100010], n, e, u, v;
vector<int>adj[100010];

void dfs(int x)
{
    visited[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
        if(!visited[adj[x][i]])
            dfs(adj[x][i]);
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cnt = 0;
    cin>>n>>e;
    for(int i = 0; i < n; i++)
        adj[i].clear();
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < e; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(i), ++cnt;
    }
    cout<<cnt<<endl;
}

return 0;}
