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

int t, n, row, last;
char seat, dir;

int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    cin>>n;
    if(n == 1)
        cout<<"poor conductor"<<endl;
    else
    {
        row = n/5;
        last = n%10;
        if(last == 2 || last == 3 || last == 4)
            ++row;
        else if(last == 9 || last == 8 || last == 7)
            ++row;
        if(last == 2 || last == 3 || last == 1 || last == 0)
            dir = 'L';
        else
            dir = 'R';
        if(last == 2 || last == 1 || last == 6 || last == 7)
            seat = 'W';
        else if(last == 5 || last == 8)
            seat = 'M';
        else
            seat = 'A';
        cout<<row<<" "<<seat<<" "<<dir<<endl;
    }
}

return 0;}
