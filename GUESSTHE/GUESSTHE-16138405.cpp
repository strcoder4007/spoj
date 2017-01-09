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
#define int long long

string s;
int ans1, ans2;
vector<int>myvec;

int lcm()
{
    int ans;
    if(myvec.size() == 1)
        return myvec[0];
    else if(myvec.size() > 1)
    {
        ans = myvec[0]*myvec[1]/__gcd(myvec[0], myvec[1]);
        for(int i = 2; i<myvec.size(); i++)
            ans = ans*myvec[i]/__gcd(myvec[i], ans);
        return ans;
    }
}

bool pass(int a, int b)
{
    if(a > b)
    {
        if(a%b == 0)
            return true;
        else
            return false;
    }
    else
    {
        if(b%a == 0)
            return true;
        else
            return false;
    }
}

main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>s && s != "*")
{
    bool found = false;
    myvec.clear();
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'Y')
            myvec.pb(i+1);
    ans1 = lcm();
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'N')
            if(ans1%(i+1) == 0)
                found = true;
    if(!found)
        cout<<ans1<<endl;
    else
        cout<<-1<<endl;
}


}
