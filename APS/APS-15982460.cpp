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
#define int unsigned long long

bool ary[10000010];
int sum[10000010];
int funk[10000010];

void esieve(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(ary[i] == false)
        {
            int ii = 2;
            while(i*ii <= n)
            {
                ary[i*ii] = true;
                if(funk[i*ii] == 0)
                    funk[i*ii] = i;
                ++ii;
            }
            funk[i] = i;
            sum[i] = sum[i-1]+i;
        }
        else
            sum[i] = sum[i-1]+funk[i];
    }
}

main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

esieve(10000010);
int t, n;
cin>>t;
while(t--)
{
    cin>>n;
    cout<<sum[n]<<endl;
}


}
