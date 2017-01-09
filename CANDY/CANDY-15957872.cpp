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


int n, sum, avg, ls, mr, ary[10010];

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


while(cin>>n && n != -1)
{
    sum = 0, ls = 0, mr = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>ary[i];
        sum += ary[i];
    }
    avg = sum/n;
    for(int i = 0; i < n; i++)
    {
        if(ary[i] < avg)
            ls += avg-ary[i];
        else
          mr += ary[i]-avg;
    }
    if(ls == mr)
        cout<<ls<<endl;
    else
        cout<<-1<<endl;
}

return 0;}
