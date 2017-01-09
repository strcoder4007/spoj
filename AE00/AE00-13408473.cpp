#include <iostream>
#include<cmath>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int answer = 0;
        for (int j = 1; j <= ((int)sqrt(n)); j++)
            answer += (n/j - j + 1);
	cout<<answer;
	return 0;
}