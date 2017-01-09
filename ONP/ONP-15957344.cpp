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


int t, n;
string s;
stack<char>mystack;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>s;
    n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            mystack.push(s[i]);
        else if(s[i] >= 97 && s[i] <= 123)
            cout<<s[i];
        else if(s[i] == ')')
        {
            char st = mystack.top();
            cout<<st;
            mystack.pop();
        }
    }
    cout<<endl;
}

return 0;}
