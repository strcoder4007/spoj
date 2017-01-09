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

int main(){
//freopen("in.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

for(int i =  6; i <= 100; i++)
    for(int j = 2; j < i-2; j++)
        for(int k = j+1; k < i-1; k++)
            for(int l = k+1; l < i; l++)
            if(i*i*i == l*l*l + j*j*j + k*k*k)
                cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
return 0;}
