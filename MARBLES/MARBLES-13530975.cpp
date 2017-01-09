#include <iostream>
#define ll long long int
using namespace std;

ll nk( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) /*return*/ k = n-k;  //remove the commented section
    if (k == 0) return 1;
 
    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		ll res = (nk(n, k) * k)/n;
		cout<<res<<endl;
	}
	return 0;
}
