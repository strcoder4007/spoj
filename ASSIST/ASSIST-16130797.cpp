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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pi 3.141592653589793
#define endl "\n"
#define fill2d(l, nm) fill_n(*l, sizeof l / sizeof **l, nm);
#define MOD 1000000007
using namespace std;

int number, ary[3000], sz;
list<int>mylist;

void esieve()
{
    for(int i = 2;i<=33850;++i)
        mylist.pb(i);
    list<int> :: iterator it,it2;
    while(!mylist.empty() && sz<3000)
    {
        ary[sz] = mylist.front();
        ++sz;
        int k = mylist.front(),i = 0;
        for(it = mylist.begin();it!=mylist.end();it = it2,++i)
        {
            it2 = it; ++it2;
            if(i%k==0)
                mylist.erase(it);
        }
    }
}

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

esieve();
while(cin>>number && number)
{
    cout<<ary[number-1]<<endl;
}

return 0;}
