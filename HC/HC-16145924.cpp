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

int t, n, a, b;
string s;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        if(s == "lxh")
            ++a;
        else
            ++b;
    }
    if(!(a&1) && !(b&1))
        cout<<"hhb"<<endl;
    else if(!(a&1) && b&1)
        cout<<"hhb"<<endl;
    else if(a&1 && !(b&1))
        cout<<"lxh"<<endl;
    else if(a&1 && b&1)
        cout<<"lxh"<<endl;
}

return 0;}
