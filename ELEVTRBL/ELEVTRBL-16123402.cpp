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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l, nm) fill_n(*l, sizeof l / sizeof **l, nm);
#define MOD 1000000007
using namespace std;

int n, start, end, up, down, fst, sec, visited[1000010], dist[1000010], x;
queue<int>myqueue;


void bfs()
{
    myqueue.push(start);
    visited[start] = 1;
    dist[start] = 0;
    while(!myqueue.empty())
    {
        x = myqueue.front();
        myqueue.pop();
        fst = x-down;
        if(fst >= 1 && !visited[fst])
            myqueue.push(fst), visited[fst] = 1, dist[fst] = dist[x]+1;
        sec = x+up;
        if(sec <= n && !visited[sec])
            myqueue.push(sec), visited[sec] = 1, dist[sec] = dist[x]+1;
    }
}

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>start>>end>>up>>down;
dist[end] = -1;
bfs();
if(dist[end] == -1)
    cout<<"use the stairs"<<endl;
else
    cout<<dist[end]<<endl;

return 0;}
