#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if (n==m || n-m == 2)
		{
			if (n == 0 && m == 0) cout<<"0"<<endl;
			else if (n%2 == 0) cout<<n+m<<endl;
			else if (n%2 != 0) cout<<n+m-1<<endl;
		}
		else cout<<"No Number"<<endl;
	}
	return 0;
}