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
#define MOD 10000007
using namespace std;

int xaxis[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
int yaxis[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int visited[101][101], next;
char ary[101][101];
string st, strn = "ALLIZZWELL";
int t, n, m;
bool found;
string ss;

string dfs(int x, int y, int idx)
{
    visited[x][y] = 1;
    //cout<<x<<" "<<y<<" "<<idx<<endl;
    if(idx == 9)
        return "YES";
    for(int i = 0; i < 8; i++)
    {
        if(ary[x+xaxis[i]][y+yaxis[i]] <= 90 && ary[x+xaxis[i]][y+yaxis[i]] >= 65 && !visited[x+xaxis[i]][y+yaxis[i]] && ary[x+xaxis[i]][y+yaxis[i]] == strn[idx+1])
            ss = dfs(x+xaxis[i], y+yaxis[i], idx+1);
        if(ss == "YES")
            return ss;
    }
    visited[x][y] = 0;
    return "NO";
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    st = "";
    ss = "NO";
    cin>>n>>m;
    found = false;
    memset(ary, 0, sizeof(ary));
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>ary[i][j];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            st = "";
            if(ary[i][j] == 'A')
                ss = dfs(i, j, 0);
            if(ss == "YES")
            {
                found = true;
                break;
            }
        }
        if(found)
            break;
    }
    if(found)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

return 0;}
