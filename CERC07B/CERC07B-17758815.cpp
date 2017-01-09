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
#include <ctime>
#include <memory.h>
#include <bitset>
#include <climits>
#include <iomanip>

#define F first
#define S second
#define endl "\n"
#define pb push_back
#define mp make_pair
#define bs 1000000007
#define pi 3.141592653589793
#define y1 kjdfshnvoavaofobiopj
using namespace std;

int n, m, ans, final_ans, newary[20][20];
vector<int>myvec;
char ary[20][20];
bool error;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool pass(int a, int b)
{
	if(a >= 0 && a < n && b >= 0 && b < m)
		return true;
	return false;
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(cin>>n && n != 0)
{
cin>>m;
for(int i = 0; i < n; i++)
	cin>>ary[i];
final_ans = INT_MAX;
for(int mask = 0; mask < (1<<m); mask++)
{
	ans = 0;
	myvec.clear();
	for(int j = 0; j < m; j++)
		if(mask&(1<<j))
			myvec.pb(1);
		else
			myvec.pb(0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(ary[i][j] == 'X')
				newary[i][j] = 1;
			else
				newary[i][j] = 0;
	for(int j = 0; j < myvec.size(); j++)
		if(myvec[j])
		{
			++ans;
			newary[0][j] ^= 1;
			int x = 0, y = j;
			for(int k = 1; k < 4; k++)
				if(pass(x+dx[k], y+dy[k]))
					newary[x+dx[k]][y+dy[k]] ^= 1;
		}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			if(newary[i-1][j])
			{
				++ans;
				newary[i][j] ^= 1;
				for(int k = 0; k < 4; k++)
					if(pass(i+dx[k], j+dy[k]))
						newary[i+dx[k]][j+dy[k]] ^= 1;
			}
	}
	error = false;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(newary[i][j])
				error = true;
	if(!error)
		final_ans = min(ans, final_ans);
}
if(final_ans == INT_MAX)
	cout<<"Damaged billboard."<<endl;
else
	cout<<"You have to tap "<<final_ans<<" tiles."<<endl;
}

return 0;}