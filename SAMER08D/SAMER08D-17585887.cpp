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
#include <iostream>
#include <stdlib.h>

#define F first
#define S second
#define endl "\n"
#define pb push_back
#define mp make_pair
#define bs 1000000007
#define pi 3.141592653589793
#define y1 kjdfshnvoavaofobiopj
using namespace std;

int k, n, m, dp[1010][1010];
char st1[1010], st2[1010];

int main(){
//freopen("input.txt", "r", stdin);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

while(1)
{
	scanf("%d", &k);
	if(!k)
		break;
	memset(dp, 0, sizeof dp);
	scanf("%s", st1+1);
	scanf("%s", st2+1);
	n = strlen(st1+1);
	m = strlen(st2+1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			for(int t = 0; t <= i; t++)
			{
				if(t >= k)
					dp[i][j] = max(dp[i][j], dp[i-t][j-t]+t);
				if(st1[i-t] != st2[j-t])
					break;
			}
		}
	printf("%d\n", dp[n][m]);
}

return 0;}
