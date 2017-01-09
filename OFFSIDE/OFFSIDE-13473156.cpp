#include <iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	while(n != 0 && m != 0)
	{
		int attacker[n], defender[m];
		for(int i = 0; i < n; i++)
		cin>>attacker[i];
		for(int i = 0; i < m; i++)
		cin>>defender[i];
		sort(defender, defender+m);
		if(defender[1] <= *min_element(attacker, attacker+n))
		cout<<"N"<<endl;
		else
		cout<<"Y"<<endl;
		cin>>n>>m;
	}
	return 0;
}