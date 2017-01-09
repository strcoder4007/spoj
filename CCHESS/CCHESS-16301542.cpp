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
#include <stdlib.h>
#include <climits>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 10000007
using namespace std;

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int dist[15][15];

bool pass(int a, int b)
{
    if(a >= 0 && a < 8 && b >= 0 && b < 8)
        return true;
    return false;
}

void bfs(pair<int, int> idx)
{
    queue<pair<int, int> >q;
    q.push(idx);
    dist[idx.F][idx.S] = 0;
    while(q.size())
    {
        pair<int, int> node = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
            if(pass(node.F+dx[i], node.S+dy[i]) && dist[node.F+dx[i]][node.S+dy[i]] > dist[node.F][node.S]+node.F*(node.F+dx[i])+node.S*(node.S+dy[i]))
            {
                q.push(mp(node.F+dx[i], node.S+dy[i]));
                dist[node.F+dx[i]][node.S+dy[i]] = dist[node.F][node.S]+node.F*(node.F+dx[i])+node.S*(node.S+dy[i]);
            }
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

int a, b, c, d;
while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dist[i][j] = INT_MAX;
    bfs(mp(a, b));
    cout<<dist[c][d]<<endl;
}

return 0;}
