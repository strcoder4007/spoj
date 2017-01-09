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


string binary[] = {"0111111", "0001010", "1011101", "1001111", "1101010", "1100111", "1110111", "0001011", "1111111", "1101011"};
unsigned long decimal[15];
string st, s, fst, sec;
int n, fstnum, secnum, num, multi, ans;
bool found;

string to_string(int number)
{
    string result;
    stringstream convert;
    convert<<number;
    result = convert.str();
    return result;
}


int main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

for(int i = 0; i < 10; i++)
    decimal[i] = bitset<8>(binary[i]).to_ulong();

while(cin>>st && st != "BYE")
{
    n = st.size();
    fst = "", sec = "", found = false, fstnum = 0, secnum = 0, multi = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(st[i] == '+')
        {
            found = true;
            continue;
        }
        if(!found)
            fst += st[i];
        else
            sec += st[i];
    }

    for(int i = fst.size()-1; i+1; i-=3)
    {
        s = fst[i-2], s += fst[i-1], s += fst[i];
        num = atoi(s.c_str());
        for(int j = 0; j < 10; j++)
            if(decimal[j] == num)
                fstnum += (multi*j), multi *= 10;
    }
    multi = 1;
    for(int i = sec.size()-1; i+1; i-=3)
    {
        s = sec[i-2], s += sec[i-1], s += sec[i];
        num = atoi(s.c_str());
        for(int j = 0; j < 10; j++)
            if(decimal[j] == num)
                secnum += multi*j, multi *= 10;
    }
    ans = fstnum + secnum;
    cout<<st;
    stringstream convert;
    convert<<ans;
    string res = convert.str();
    for(int i = 0; i < res.size(); i++)
    {
        if(to_string(decimal[res[i]-48]).size() == 1)
            cout<<"00";
        else if(to_string(decimal[res[i]-48]).size() == 2)
            cout<<"0";
        cout<<decimal[res[i]-48];
    }
    cout<<endl;
}

return 0;}
