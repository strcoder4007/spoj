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
#define int long long

int cnt, ary[200020], t, n;

void merge(int l, int mid, int r)
{
    int temp[200020];
    int i = l, j = mid+1, k = l;
    while(i <= mid && j <= r)
    {
        if(ary[i] <= ary[j])
            temp[k++] = ary[i++];
        else
        {
            temp[k] = ary[j];
            cnt += (mid-i+1)*ary[j];
            ++k, ++j;
        }
    }
    while(i <= mid)
        temp[k++] = ary[i++];
    while(j <= r)
        temp[k++] = ary[j++];
    for(int i = l; i <= r; i++)
        ary[i] = temp[i];
}

void merge_sort(int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)>>1;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, r);
    }
}

main(){
//freopen("input.txt", "r", stdin);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
    memset(ary, 0, sizeof ary);
    cnt = 0;
    cin>>n;
    for(int i = n; i; i--)
        cin>>ary[i];
    merge_sort(1, n);
    cout<<cnt<<endl;
}

}
