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

string ary[1010];
int n, m, cnt, visited[1010][1010], num, save[1010][1010];
stack<pair<int, int> >mystack;
set<int>myset;

bool pass(int a, int b)
{
    if(a >= 0 && a < n && b >= 0 && b < m)
        return true;
    return false;
}

void dfs(pair<int, int> node)
{
    visited[node.F][node.S] = 1;
    int i = node.F, j = node.S;
    if(save[i][j] != 0)
    {
        while(mystack.size())
            save[mystack.top().F][mystack.top().S] = save[i][j], mystack.pop();
        return;
    }
    else
        mystack.push(node), save[i][j] = num;

    if(ary[i][j] == 'N' && pass(i-1, j))
        dfs(mp(i-1, j));
    if(ary[i][j] == 'S' && pass(i+1, j))
        dfs(mp(i+1, j));
    if(ary[i][j] == 'E' && pass(i, j+1))
        dfs(mp(i, j+1));
    if(ary[i][j] == 'W' && pass(i, j-1))
        dfs(mp(i, j-1));
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for(int i = 0; i < n; i++)
    cin>>ary[i];

for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(!visited[i][j])
            ++num, dfs(mp(i, j));
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        myset.insert(save[i][j]);

cout<<myset.size()<<endl;

return 0;}
