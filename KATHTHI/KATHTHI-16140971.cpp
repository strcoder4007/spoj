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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char ary[1010][1010];
int t, n, m, visited[1010][1010];
pair<int, int> start = mp(1, 1), idx;
deque<pair<int, int> >myqueue;

void bfs(pair<int, int> node)
{
    myqueue.push_front(node);
    visited[node.F][node.S] = 0;
    while(!myqueue.empty())
    {
        idx = myqueue.front();
        myqueue.pop_front();
        if(idx.F == n && idx.S == m)
            break;
        for(int i = 0; i < 4; i++)
            if(idx.F+dx[i] >= 1 && idx.F+dx[i] <= n && idx.S+dy[i] >= 1 && idx.S+dy[i] <= m)
            {
                if(ary[idx.F+dx[i]][idx.S+dy[i]] == ary[idx.F][idx.S] && visited[idx.F+dx[i]][idx.S+dy[i]] > visited[idx.F][idx.S])
                    visited[idx.F+dx[i]][idx.S+dy[i]] = visited[idx.F][idx.S], myqueue.push_front(mp(idx.F+dx[i], idx.S+dy[i]));
                else if(visited[idx.F+dx[i]][idx.S+dy[i]] > visited[idx.F][idx.S]+1)
                    visited[idx.F+dx[i]][idx.S+dy[i]] = visited[idx.F][idx.S]+1, myqueue.push_back(mp(idx.F+dx[i], idx.S+dy[i]));
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
    myqueue.clear();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>ary[i][j];
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            visited[i][j] = INT_MAX;

    bfs(start);
    cout<<visited[n][m]<<endl;
}


return 0;}
