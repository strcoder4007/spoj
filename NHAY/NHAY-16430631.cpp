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
#include <stdlib.h>
#include <climits>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define M_pi 3.141592653589793
#define endl "\n"
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 1000000007
using namespace std;

string s,t, st;
int junk;
vector<int>pi;

void prefix_function ()
{
	int n = st.size();
    pi = vector<int>(n);
	for (int i=1; i < n; ++i)
    {
		int j = pi[i-1];
		while (j > 0 && st[i] != st[j])
			j = pi[j-1];
		if (st[i] == st[j])  ++j;
		pi[i] = j;
	}
}


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>junk)
{
    cin>>s>>t;
    st = s+'#'+t;
    prefix_function();
    for(int i = 0; i < pi.size(); i++)
        if(pi[i] == junk)
            cout<<i-junk-s.size()<<endl;
    cout<<endl;
}

return 0;}
