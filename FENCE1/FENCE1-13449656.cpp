#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double b,d;

	cin>>b;
	while(b!=0)
	{

		d=(b*b)/(atan(1.0)*8);
		printf("%.2f\n",d);
		cin>>b;
	}
	return 0;
}