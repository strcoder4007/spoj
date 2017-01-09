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


long long  t, num, temp, n, ans, rem;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>num;
    temp=0, n=0;
    while(temp<num)
    {
        n=n+1;
        temp=pow(2,n+1)-2;
    }
    temp=pow(2,n)-2;
    ans=num-temp-1;
    char str[100000];
    int k=-1;
    while(ans>0)
    {
        rem=ans%2;
        k=k+1;
        str[k]=rem+'0';
        ans=ans/2;
    }
    int j=n-k-1;
    for(int i=1;i<=j;i++)
        cout<<5;
    for(int i=k;i>=0;i--)
    {
        if(str[i]=='0')
            cout<<5;
        else
            cout<<6;
    }
    cout<<endl;
}

return 0;}
