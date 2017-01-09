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

vector<int>myvec;
int n, cnt, found[10010];
string st;
vector<int>adj[10010];

bool ary[10050];
void esieve(int num)
{
    for(int i = 2; i < num; i++)
        if(ary[i] == false)
        {
            int ii = 2;
			myvec.pb(i);
            while(i*ii <= num)
                ary[i*ii] = true, ++ii;
        }
}

string str(int num)
{
	string Result;
	stringstream convert;
	convert << num;
	Result = convert.str();
	return Result;
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

esieve(10010);
cin>>n;
for(int i = 2; i <= n; i++)
{
	int num = i;
	for(int j = 0; j < myvec.size(); j++)
	{
		cnt = 0;
		while(num%myvec[j] == 0)
			num /= myvec[j], ++cnt;
		found[myvec[j]] += cnt;
	}
}
for(int i = 2; i <= 10000; i++)
	if(found[i] != 0)
		st += str(i)+'^'+str(found[i])+" * ";
for(int i = 0; i < st.size()-3; i++)
	cout<<st[i];
cout<<endl;

return 0;}
