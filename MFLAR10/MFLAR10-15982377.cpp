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

string st;
int n, start, end;
bool error;
char letter;


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

while(getline(cin, st) && st != "*")
{
    n = st.size();
    error = false;
    for(int i = 0; i < n; i++)
        if(st[i] != ' ')
        {
            start = i;
            break;
        }
        for(int i = n-1; i+1; i--)
            if(st[i] != ' ')
            {
                end = i;
                break;
            }
    letter = st[start];
    for(int i = start; i <= end; i++)
        if(st[i] == ' ' && (st[i+1] != toupper(letter) && st[i+1] != tolower(letter)))
        {
            cout<<"N"<<endl;
            error = true;
            break;
        }
    if(!error)
        cout<<"Y"<<endl;
}


return 0;}
