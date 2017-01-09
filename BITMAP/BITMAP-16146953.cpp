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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int t, n, m, dist[200][200];
pair<int, int>idx;
queue<pair<int, int> >q;
string ary[200];

int pass(int xs, int xd)
{
    if(xs >= 0 && xs < n && xd >= 0 && xd < m)
        return 1;
    return 0;
}

void bfs(pair<int, int>node)
{
    q.push(node);
    dist[node.F][node.S] = 0;
    while(!q.empty())
    {
        idx = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            if(pass(idx.F+dx[i], idx.S+dy[i]) && dist[idx.F+dx[i]][idx.S+dy[i]] > dist[idx.F][idx.S]+abs(dx[i])+abs(dy[i]))
            {
                dist[idx.F+dx[i]][idx.S+dy[i]] = dist[idx.F][idx.S]+abs(dx[i])+abs(dy[i]);
                q.push(mp(idx.F+dx[i], idx.S+dy[i]));
            }
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    for(int i = 0; i < n; i++)
            cin>>ary[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = INT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ary[i][j] == '1')
                bfs(mp(i, j));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }

}

return 0;}
