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
#include <climits>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l, nm) fill_n(*l, sizeof l / sizeof **l, nm);
#define MOD 1000000007
using namespace std;

int power, found[15], k, n;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

power = 0;
found[1] = 1;
for(int i = 2; i < 11; i++)
	found[i] = pow(i, power), ++power;

while(cin>>n && n)
{
	++k;
	cout<<"Case "<<k<<", N = "<<n<<", # of different labelings = "<<found[n]<<endl;
}


return 0;}
