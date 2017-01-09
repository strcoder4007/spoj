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
int n, m, dist[30][30];
pair<int, int>start, end, idx;
char ary[30][30];
queue<pair<int, int> >q;


void bfs(pair<int, int> node)
{
    q.push(node);
    dist[node.F][node.S] = 0;
    while(!q.empty())
    {
        idx = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            if(ary[idx.F+dx[i]][idx.S+dy[i]] != 'X' && ary[idx.F+dx[i]][idx.S+dy[i]] != 'S' && dist[idx.F][idx.S]+(ary[idx.F+dx[i]][idx.S+dy[i]]-48) < dist[idx.F+dx[i]][idx.S+dy[i]]
            && idx.F+dx[i] >= 1 && idx.F+dx[i] <= n && idx.S+dy[i] >= 1 && idx.S+dy[i] <= m)
            {
                dist[idx.F+dx[i]][idx.S+dy[i]] = dist[idx.F][idx.S]+(ary[idx.F+dx[i]][idx.S+dy[i]]-48);
                if(ary[idx.F+dx[i]][idx.S+dy[i]] != '0')
                    q.push(mp(idx.F+dx[i], idx.S+dy[i]));
            }
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>m && m)
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin>>ary[i][j];
            if(ary[i][j] == 'S')
                start = mp(i, j);
            if(ary[i][j] == 'D')
                end = mp(i, j), ary[i][j] = '0';
            dist[i][j] = INT_MAX;
        }
    bfs(start);
    while(!q.empty())
        q.pop();
    cout<<dist[end.F][end.S]<<endl;
}

return 0;}
