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

int t, k, a, b, c, gcd;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
k = t;
while(t--)
{
    cin>>a>>b>>c;
    gcd = __gcd(a, b);
    if(c%gcd == 0)
        cout<<"Case "<<k-t<<": Yes"<<endl;
    else
        cout<<"Case "<<k-t<<": No"<<endl;
}


return 0;}
