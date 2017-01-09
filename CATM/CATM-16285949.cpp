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

int n, m, t, mx, my, cx1, cx2, cy1, cy2, minn, distm, distc1, distc2;
bool found;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m>>t;
while(t--)
{
    found = false;
    cin>>mx>>my>>cx1>>cy1>>cx2>>cy2;
    minn = INT_MAX;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(i == 0 || j == 0 || i == n || j == m)
            {
                distm = abs(mx-i)+abs(my-j);
                distc1 = abs(cx1-i)+abs(cy1-j);
                distc2 = abs(cx2-i)+abs(cy2-j);
                if(distm < distc1 && distm < distc2)
                    found = true;
            }
    if(found)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

return 0;}
