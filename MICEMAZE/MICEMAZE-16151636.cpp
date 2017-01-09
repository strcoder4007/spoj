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

int n, e, t, m, x, y, val, cnt, dist[101];
vector<pair<int, int> >adj[101];
queue<int>q;


void bfs(int node)
{
    q.push(node);
    dist[node] = 0;
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int i = 0; i < adj[idx].size(); i++)
        {
            x = adj[idx][i].F, y = adj[idx][i].S;
            if(dist[x] > dist[idx]+y)
                dist[x] = dist[idx]+y, q.push(x);
        }
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>e>>t>>m;
for(int i = 0; i < m; i++)
{
    cin>>x>>y>>val;
    adj[x].pb(mp(y, val));
}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= 100; j++)
        dist[j] = INT_MAX;
    bfs(i);
    if(dist[e] <= t)
        ++cnt;
}
cout<<cnt<<endl;

return 0;}
