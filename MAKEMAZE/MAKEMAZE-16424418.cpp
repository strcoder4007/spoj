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
#define MOD 1000000007
using namespace std;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int t, n, m, visited[25][25], dots;
char ary[25][25];
vector<pair<int, int> >myvec;

bool pass(int a, int b)
{
    if(a > 0 && a <= n && b > 0 && b <= m && ary[a][b] == '.')
        return true;
    return false;
}

void dfs(pair<int, int> idx)
{
    int x = idx.F, y = idx.S;
    visited[x][y] = 1;
    if(idx == myvec[1])
        return;
    for(int i = 0; i < 4; i++)
        if(pass(x+dx[i], y+dy[i]) && !visited[x+dx[i]][y+dy[i]])
            dfs(mp(x+dx[i], y+dy[i]));
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n>>m;
    memset(visited, 0, sizeof visited);
    myvec.clear(), dots = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin>>ary[i][j];
            if(((i == 1 || i == n) || (j == 1 || j == m)) && ary[i][j] == '.')
                ++dots, myvec.pb(mp(i, j));
        }
    if(dots != 2)
    {
        cout<<"invalid"<<endl;
        continue;
    }
    dfs(myvec[0]);
    if(visited[myvec[1].F][myvec[1].S])
        cout<<"valid"<<endl;
    else
        cout<<"invalid"<<endl;
}

return 0;}
