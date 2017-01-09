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

int visited[100010], cycle, n, m, u, v, cnt, last;
vector<int>adj[10010];
bool found;

void dfs(int x)
{
    visited[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
        if(!visited[adj[x][i]])
            dfs(adj[x][i]);
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for(int i = 0; i < m; i++)
{
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
for(int i = 1; i <= n; i++)
{
    last = i;
    if(!visited[i])
        dfs(i), ++cnt;
}
if(cnt > 1 || n-1 != m)
    cout<<"NO"<<endl;
else
    cout<<"YES"<<endl;



return 0;}
