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

int xaxis[4] = {-1, 0, 1, 0};
int yaxis[4] = {0, 1, 0, -1};
char ary[1010][1010];
int visited[1010][1010], dist[1010][1010], t, n, m, maxx, fst, sec;
pair<int, int> last;
queue<pair<int, int> >myqueue;
vector<pair<int, int> >myvec;

void bfs(int x, int y)
{
    visited[x][y] = 1;
    dist[x][y] = 0;
    myqueue.push(mp(x, y));
    while(!myqueue.empty())
    {
        pair<int, int> node = myqueue.front();
        fst = node.F;
        sec = node.S;
        maxx = max(maxx, dist[fst][sec]);
        myqueue.pop();
        for(int i = 0; i < 4; i++)
            if(ary[fst+xaxis[i]][sec+yaxis[i]] == '.' && fst+xaxis[i] >= 1 && fst+xaxis[i] <= n && sec+yaxis[i] >= 1 && sec+yaxis[i] <= m && !visited[fst+xaxis[i]][sec+yaxis[i]])
            {
                visited[fst+xaxis[i]][sec+yaxis[i]] = 1;
                dist[fst+xaxis[i]][sec+yaxis[i]] = dist[fst][sec]+1;
                if(dist[fst+xaxis[i]][sec+yaxis[i]] > maxx)
                    maxx = dist[fst+xaxis[i]][sec+yaxis[i]], last = mp(fst+xaxis[i], sec+yaxis[i]);
                myqueue.push(mp(fst+xaxis[i], sec+yaxis[i]));
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
    cin>>m>>n;
    maxx = -1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>ary[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m ; j++)
            if(ary[i][j] == '.')
                myvec.pb(mp(i, j));

    memset(visited, 0, sizeof(visited));
    bfs(myvec[0].F, myvec[0].S);
    memset(visited, 0, sizeof(visited));
    dist[last.F][last.S] = 0;
    maxx = -1;
    bfs(last.F, last.S);
    cout<<"Maximum rope length is "<<maxx<<"."<<endl;
}

return 0;}
