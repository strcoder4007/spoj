#include<bits/stdc++.h>
using namespace std;
int main (void)
{
	float a,b;
	cin>>a>>b;
	while (a != -1 && b != -1)
	{
		if (a == 0 && b == 0)
		cout<<"0"<<endl;
		else if(a == 0 && b != 0)
		cout<<b<<endl;
		else if(a != 0 && b == 0)
		cout<<a<<endl;
		else
		{
			float r;
			if( a > b )
				r = ceil( (double)a/(b+1) );
			else
				r = ceil( (double)b/(a+1) );
			cout << r << endl;
		}
		cin>>a>>b;
	}
}