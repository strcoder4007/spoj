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
#define MOD 10000007
using namespace std;

unsigned long long n, num, ans;
string ss;

int count(int x)
{
    int cnt = 0;
    while(x > 1)
        x /= 2, ++cnt;
    return cnt;
}

int main(){
///freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for(int i = 0; i < n; i++)
{
    cin>>num;
    if(!(num&1))
    {
        ss = "";
        int sz = count(num);
        bitset<25>mybitset = num;
        string st = mybitset.to_string();
        reverse(st.begin(), st.end());
        for(int j = 0; j <= sz; j++)
            ss += st[j];
        bitset<25> newbitset(ss);
        num = newbitset.to_ulong();
    }
    cout<<num<<endl;
}

return 0;}
