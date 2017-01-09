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


string s;
int n, calc, skip, col;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


while(cin>>col && col != 0)
{
    cin>>s;
    n = s.size();
    calc = (col-1)*2+1;
    skip = 1;
    for(int xs = 0; xs < col; xs++)
    {
        for(int i = xs; i < n; i+=calc)
        {
            if(i == xs)
                cout<<s[i];
            else
            {
                cout<<s[i]<<s[i+skip];
                i+=skip;
            }
        }
        calc -= 2;
        skip += 2;
    }
    cout<<endl;
}

return 0;}
