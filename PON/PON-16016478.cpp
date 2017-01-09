#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <list>
#include <ctime>
#include <memory.h>
#include <bitset>
#include <limits.h>
#include <stdlib.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 10000007
using namespace std;

unsigned long long t, n;
#define LL unsigned long long

LL mulmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
LL power(LL a,LL b,LL n){
	if(b==0)
		return 1;
	if(b==1) return a%n;
		LL c=power(a,b/2,n);
		LL p=mulmod(c%n,c%n,n);
		if(b%2==0)
			return p;
		else
			 return (mulmod(p,a,n));
}

bool miller_rabin(unsigned long long p, int it)
{
	if(p<2) return false;
	if(p==2) return true;
	if((p&1)==0) return false;

	unsigned long long s = p-1;
	while(s%2==0) s >>= 1;

	while(it--){
		unsigned long long a = rand()%(p-1)+1,temp = s;
		unsigned long long  mod = power(a,temp,p);

		if(mod==-1 || mod==1) continue;

		while(temp!=p-1 && mod!=p-1){
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}

		if(mod!=p-1) return false;
	}

	return true;
}


int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>t;
while(t--)
{
    cin>>n;
    if(miller_rabin(n, 18))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}


return 0;}
