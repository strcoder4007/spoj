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

long long t, n, u, v, wt, visited[50010], last, dist[50010], maxx;
vector<pair<long long, long long> >adj[50010];
queue<long long>q;


void bfs1(long long x)
{
    q.push(x);
    visited[x] = 1;
    memset(dist, 0, sizeof dist);
    memset(visited, 0, sizeof visited);
    while(q.size())
    {
        long long xs = q.front();
        visited[xs] = 1;
        q.pop();
        for(long long i = 0; i < adj[xs].size(); i++)
            if(!visited[adj[xs][i].F] && dist[adj[xs][i].F] < dist[xs]+adj[xs][i].F)
                q.push(adj[xs][i].F), dist[adj[xs][i].F] = dist[xs]+adj[xs][i].S;
    }
}

void bfs2(long long x)
{
    q.push(x);
    memset(dist, 0, sizeof dist);
    memset(visited, 0, sizeof visited);
    visited[x] = 1;
    while(q.size())
    {
        long long xs = q.front();
        visited[xs] = 1;
        q.pop();
        for(long long i = 0; i < adj[xs].size(); i++)
            if(!visited[adj[xs][i].F] && dist[adj[xs][i].F] < dist[xs]+adj[xs][i].S)
                q.push(adj[xs][i].F), dist[adj[xs][i].F] = dist[xs]+adj[xs][i].S;
    }
}


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    maxx = 0;
    memset(dist, 0, sizeof dist);
    memset(visited, 0, sizeof visited);
    for(long long i = 1; i <= n; i++)
        adj[i].clear();
    for(long long i = 1; i < n; i++)
    {
        cin>>u>>v>>wt;
        adj[u].pb(mp(v, wt));
        adj[v].pb(mp(u, wt));
    }
    bfs1(1);
    for(long long i = 1; i <= n; i++)
        if(maxx < dist[i])
            maxx = dist[i], last = i;
    bfs1(last);
    maxx = *max_element(dist+1, dist+n+1);
    cout<<maxx<<endl;
}

return 0;}
