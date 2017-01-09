#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		double s = (a+b+c+d)/2;
		double res = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n", res);
	}
	return 0;
}
