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

int t, n, ary[210][210];

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>ary[i][j];

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            int k;
            for(k = 0; k < n; k++)
                if (k != i && k != j && ary[i][k] + ary[k][j] == ary[i][j])
                    break;
            if (k == n)
                cout<<i+1<<" "<<j+1<<endl;
        }
    if(t > 0)
        cout<<endl;
}

return 0;}
