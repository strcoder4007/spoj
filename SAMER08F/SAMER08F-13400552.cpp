#include<iostream>
using namespace std;
int main (void)
{
	int n;
    while (cin>>n)
{
	int res;
	res = static_cast<int>(n*(n+1)*(2*n+1)/6);
	if (res == 0)	cout<<endl;
	else	cout<<res<<endl;
}
}