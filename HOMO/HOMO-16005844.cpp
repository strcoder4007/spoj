#include <set>
#include <list>
#include <map>
#include <stack>
#include <bitset>
#include <ctime>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <complex>
#include <iostream>
#include <algorithm>
#include <memory.h>

#define F first
#define endl "\n"
#define S second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pi 3.141592653589793
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
using namespace std;

string st;
bool found;
multiset<int>::iterator it;
multiset<int>mymultiset;
int n, num, hetero=0, homo=0, cnt, sz=0;

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>n;
while(n--)
{
    found = false;
    cin>>st>>num;
    if(sz == 0)
    {
        homo=hetero=0;
        if(st[0]=='i')
            mymultiset.insert(num), ++sz;
        found = true;
    }
    else
    {
        if(st[0]=='i')
        {
            mymultiset.insert(num);
            cnt = mymultiset.count(num);
            if(cnt == 1)
                hetero++;
            if(cnt == 2)
                homo++;
            ++sz;
        }
        if(st[0] == 'd')
        {
            it = mymultiset.find(num);
            if(it != mymultiset.end())
            {
                mymultiset.erase(it);
                ++sz;
                cnt = mymultiset.count(num);
                if(cnt == 0)
                    hetero--;
                if(cnt == 1)
                    homo--;
            }
            if(sz <= 1)
                found = true;
        }
    }
    if(found)
        cout<<"neither"<<endl;
    else if(hetero>0 && homo>0)
        cout<<"both"<<endl;
    else if(hetero>0)
        cout<<"hetero"<<endl;
    else if(homo>0)
        cout<<"homo"<<endl;
    else
        cout<<"neither"<<endl;
     }

return 0;}
