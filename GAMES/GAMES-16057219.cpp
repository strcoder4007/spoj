
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

int test, upper, lower, calc, xs, sz;
string st, s, t;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>test;
while(test--)
{
    cin>>st;
    xs = 0;
    t = "";
    s = "1";
    while(st[xs] != '.' && xs < st.size()-1)
        ++xs;
    if(xs == st.size()-1)
    {
        cout<<1<<endl;
        continue;
    }
    sz = st.size()-1-xs;
    for(int i = 0; i < st.size(); i++)
        if(st[i] != '.')
            t += st[i];
    upper = atoi(t.c_str());
    for(int i = 0; i < sz; i++)
        s += '0';
    lower = atoi(s.c_str());
    //cout<<lower<<" "<<upper<<endl;
    calc = lower/__gcd(upper, lower);
    cout<<calc<<endl;
}


return 0;}


/*
#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long gcd(long a,long b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
    freopen("in.txt", "r", stdin);
 int t,count,i,flage;
 scanf("%d",&t);
 while(t--)
 {
  string s;
  cin>>s;
  long number=1,frac;
  count=0;
  flage=0;
  for(i=s.size()-1;i>=0;i--)
  {
   if(s[i]=='.')
   {
    flage=1;
    break;
   }
   else
    count++;
  }
  for(i=0;i<s.size();i++)
  {
   if(s[i]!='.')
   {
    number=number*10 + (s[i]-48);
   }
  }
  frac=1;
  if(flage)
   frac=pow(10,count);
   cout<<frac<<" "<<number<<endl;
  printf("%ld\n",frac/gcd(number,frac));
 }
 return 0;
}
*/
