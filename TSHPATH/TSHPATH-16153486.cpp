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


int t, n, m, x, y, qq, start, end;
char st[11], ss[11], tt[11];
vector<vector<pair<int, int> > >adj;


int dijkstra(pair<int, int> node)
{
    set<pair<int, int> >q;
    q.insert(node);
    vector<int>dist(n+5, 1e9);
    dist[node.S] = 0;
    while(1)
    {
        set<pair<int, int> >::iterator it = q.begin();
        pair<int, int> idx = *it;
        q.erase(q.begin());
        if(idx.S == end)
            return idx.F;
        if (dist[idx.S] < idx.F)
            continue;
        for(int i = 0; i < adj[idx.S].size(); i++)
        {
            x = adj[idx.S][i].S, y = adj[idx.S][i].F;
            if(dist[x] > idx.F+y)
                dist[x] = idx.F+y, q.insert(mp(dist[x], x));
        }
    }
}

int main(){
//freopen("input.txt", "r", stdin);

scanf("%d", &t);
while(t--)
{
    scanf("%d", &n);
    map<string, int>mymap;
    adj = vector<vector<pair<int, int> > >(n+5);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", &st);
        mymap[st] = i;
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &x, &y);
            adj[i].pb(mp(y, x));
        }
    }
    scanf("%d", &qq);
    while(qq--)
    {
        scanf("%s %s", &ss, &tt);
        start = mymap[ss], end = mymap[tt];
        printf("%d\n", dijkstra(mp(0, start)));
    }
}

return 0;}
