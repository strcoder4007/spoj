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

int t, n, u, v, dist[100010], maxx, node, ans, visited[100010];
vector<int>adj[100010];


void dfs(int x, int distance)
{
    visited[x] = 1;
    dist[x] = distance;
    for(int i = 0; i < adj[x].size(); i++)
        if(!visited[adj[x][i]])
            dfs(adj[x][i], distance+1);
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    for(int i = 0; i < n; i++)
        adj[i].clear(), visited[i] = 0, dist[i] = 0;
    maxx = -1;
    for(int i = 0; i  <n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 0);
    node = max_element(dist, dist+n)-dist;
    memset(visited, 0, sizeof(visited));
    dfs(node, 0);
    ans = *max_element(dist, dist+n);
    if(ans&1)
        ans = (ans>>1)+1;
    else
        ans = (ans>>1);
    cout<<ans<<endl;
}

return 0;}
