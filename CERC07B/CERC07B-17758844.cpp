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

int n, m, ans, final_ans, newary[17][17], myvec[17];
char ary[17][17];
bool error;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
//freopen("input.txt", "r", stdin);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

while(1)
{
	scanf("%d %d", &n, &m);
	if(n == 0)
		break;
	for(int i = 0; i < n; i++)
		scanf("%s", ary[i]);
	final_ans = INT_MAX;
	for(int mask = 0; mask < (1<<m); mask++)
	{
		ans = 0;
		for(int j = 0; j < m; j++)
			if(mask&(1<<j))
				myvec[j] = 1;
			else
				myvec[j] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(ary[i][j] == 'X')
					newary[i][j] = 1;
				else
					newary[i][j] = 0;
		for(int j = 0; j < m; j++)
			if(myvec[j])
			{
				++ans;
				newary[0][j] ^= 1;
				int x = 0, y = j;
				for(int k = 1; k < 4; k++)
					if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < m)
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
						if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m)
							newary[i+dx[k]][j+dy[k]] ^= 1;
				}
		}
		error = false;
		for(int i = 0; i < n && !error; i++)
			for(int j = 0; j < m; j++)
				if(newary[i][j])
				{
					error = true;
					break;
				}
		if(!error)
			final_ans = min(ans, final_ans);
	}
	if(final_ans == INT_MAX)
		printf("Damaged billboard.\n");
	else
		printf("You have to tap %d tiles.\n", final_ans);
}

return 0;}
