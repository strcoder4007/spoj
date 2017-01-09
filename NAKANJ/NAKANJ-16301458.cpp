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
int times, dist[15][15];
string s, t;
pair<int, int> start, dest;

bool pass(int a, int b)
{
    if(a >= 1 && a <= 8 && b >= 1 && b <= 8)
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
        //cout<<node.F<<" "<<node.S<<endl;
        q.pop();
        for(int i = 0; i < 8; i++)
            if(pass(node.F+dx[i], node.S+dy[i]) && dist[node.F+dx[i]][node.S+dy[i]] > dist[node.F][node.S]+1)
                q.push(mp(node.F+dx[i], node.S+dy[i])), dist[node.F+dx[i]][node.S+dy[i]] = dist[node.F][node.S]+1;
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>times;
while(times--)
{
    cin>>s>>t;
    fill2d(dist, INT_MAX);
    start = mp(s[0]-96, s[1]-48);
    dest = mp(t[0]-96, t[1]-48);
    bfs(start);
    cout<<dist[dest.F][dest.S]<<endl;
}

return 0;}
