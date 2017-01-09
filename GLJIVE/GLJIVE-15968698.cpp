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

vector<int>myvec;
int ary[12], newary[12], sum, ans, minn, n = 10;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

for(int i = 1; i <= 10; i++)
{
    cin>>ary[i];
    newary[i] = newary[i-1] + ary[i];
}
int low = lower_bound(newary+1, newary+11, 100)-newary;
if(newary[low] == 100)
    cout<<100<<endl;
else
{
    if(abs(newary[low-1]-100) < abs(newary[low]-100))
        cout<<newary[low-1]<<endl;
    else
        cout<<newary[low]<<endl;
}

return 0;}
