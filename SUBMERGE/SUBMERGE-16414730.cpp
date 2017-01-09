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

int visited[10010], timer, children[10010], disc[10010], low[10010], parent[10010], n, m, cnt;
vector<int>adj[10010];
set<int>myset;

void dfs(int u)
{
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            ++children[u];
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && children[u] > 1)
                myset.insert(u);
            if(parent[u] != -1 && low[v] >= disc[u])
                myset.insert(u);
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n>>m && n)
{
    cnt = 0;
    for(int i = 1; i <= n; i++)
        adj[i].clear(), visited[i] = 0, parent[i] = -1, low[i] = INT_MAX, disc[i] = INT_MAX, children[i] = 0;
    myset.clear();
    while(m--)
    {
        int u, v; cin>>u>>v;
        if(u == v)
            continue;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    cout<<myset.size()<<endl;
}

return 0;}
