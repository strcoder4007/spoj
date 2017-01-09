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
#define MOD 1000000007
using namespace std;

int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, m, ans, len, visited[51][51], dist[51][51], next, k;
char ary[51][51];
queue<pair<int, int> > myqueue;
pair<int, int> node;

void bfs(pair<int, int>idx)
{
    myqueue.push(idx);
    ++visited[idx.F][idx.S];
    dist[idx.F][idx.S] = 1;
    while(!myqueue.empty())
    {
        idx.F = myqueue.front().F;
        idx.S = myqueue.front().S;
        len = max(len, dist[idx.F][idx.S]);
        for(int i = 0; i < 8; i++)
        {
            node.F = idx.F+dx[i];
            node.S = idx.S+dy[i];
            if(visited[node.F][node.S] < 8&& node.F >= 1 && node.F <= n && node.S >= 1 && node.S <= m && ary[node.F][node.S] == ary[idx.F][idx.S]+1)
            {
                ++visited[node.F][node.S];
                dist[node.F][node.S] = dist[idx.F][idx.S]+1;
                myqueue.push(node);
            }
        }
        myqueue.pop();
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n && n)
{
    cin>>m;
    ans = 0;
    ++k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>ary[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(ary[i][j] == 'A')
            {
                len = 0;
                memset(visited, 0, sizeof visited);
                bfs(mp(i, j));
                ans = max(ans, len);
            }
    cout<<"Case "<<k<<": "<<ans<<endl;
}


return 0;}
