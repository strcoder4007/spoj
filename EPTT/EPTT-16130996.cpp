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

int n, cnt, found[1500], start, next;
bool inwhile;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for(int i = 0; i < n; i++)
{
    int xs; cin>>xs;
    ++found[xs];
}
for(int i = 0; i <= 1410; i++)
    while(found[i] != 0)
    {
        start = 1, --found[i], next = i+30;
        while(start <= 3 && found[next] != 0)
            --found[next], ++start, next += 30;
        ++cnt;
    }
cout<<cnt<<endl;

return 0;}
