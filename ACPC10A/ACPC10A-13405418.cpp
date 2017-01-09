#include<iostream>
using namespace std;
int main(void)
{
	int a1, a2, a3;
	while (1)
	{
		cin>>a1>>a2>>a3;
		if (a1 == 0 && a2 ==0 && a3 == 0)
		break;
		else{
            if (2*a2 == a3+a1)
                cout<<"AP "<<2*a3-a2<<endl;
            else
                cout<<"GP "<<a3*a3/a2<<endl;
		}
	}
}