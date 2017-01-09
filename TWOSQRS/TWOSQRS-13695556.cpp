#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define sqr(x) (x)*(x)
#define For(i,n,m) for(int i=n;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef vector<vector<pair<int,int> > > adjL;
int main()
{
	//freopen("input.txt","r",stdin);
	int cases;
	cin>>cases;
	rep(i,cases)
	{
		ll n;
		cin>>n;
		bool found=false;
		ll start=sqrt(n/2.0)-1;
		for(ll i=start;i*i<=n;i++)
		{
			ll rem=n-i*i;
			double root=sqrt((double)rem);
			ll rot=root;
			if(rot*rot==rem)
			{
				found=true;
				break;
			}
		}
		if(found)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}