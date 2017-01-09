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
#define MOD 1000000007
using namespace std;

long long hash[500050], newnum, n;
set<long long>myset;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

hash[0] = 0, hash[1] = 1;
myset.insert(0);
myset.insert(1);
for(int i = 2; i <= 500000; i++)
{
    newnum = hash[i-1]-i;
    if(myset.find(newnum) == myset.end() && newnum > 0)
        hash[i] = newnum, myset.insert(newnum);
    else
        hash[i] = newnum+2*i, myset.insert(newnum+2*i);
}
while(cin>>n && n != -1)
{
    cout<<hash[n]<<endl;
}


return 0;}
