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
#define mp make_pair
#define pb push_back
#define bs 1000000007
#define pi 3.141592653589793
#define y1 kjdfshnvoavaofobiopj
#define minn(xxx, yyy, zzz) min(xxx, min(yyy, zzz))
using namespace std;

int t, n, m, ans, final_ans, ary[55];

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
	cin>>n>>m;
	final_ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = 0;
		for(int j = 1; j <= m; j++)
			cin>>ary[j];
		for(int j = m; j; j--)
			ans = ary[j] - (ary[j] <= ans);
		final_ans ^= ans;
	}
	if(final_ans == 0)
		cout<<"SECOND"<<endl;
	else
		cout<<"FIRST"<<endl;
}


return 0;}
