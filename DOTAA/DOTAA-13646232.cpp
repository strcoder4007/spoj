#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		int n, m, d, h, count = 0;
		cin>>n>>m>>d;
		while(n--)
		{
			cin>>h;
			if (h > d)
			{
				while(h > 0)
				{
					h -= d;
					count++;
				}
				count--;
			}
		}
		if(count < m)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	
	return 0;
}
