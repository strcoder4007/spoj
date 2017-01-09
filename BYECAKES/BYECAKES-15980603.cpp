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

int ary1[6], ary2[6], idx, has_to_be_made, calc, maxx;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>ary1[1] && ary1[1] != -1)
{
    cin>>ary1[2]>>ary1[3]>>ary1[4]>>ary2[1]>>ary2[2]>>ary2[3]>>ary2[4];
    has_to_be_made = -1;
    for(int i = 1; i < 5; i++)
        has_to_be_made = max(has_to_be_made, int(ceil((float)ary1[i]/(float)ary2[i])));
    for(int i = 1; i < 5; i++)
        calc = has_to_be_made*ary2[i]-ary1[i], cout<<calc<<" ";
    cout<<endl;
}

return 0;}
