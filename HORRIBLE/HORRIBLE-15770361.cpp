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
#define fill2d(l,nm) fill_n(*l, sizeof l/sizeof **l,nm);
#define MOD 1000000007
#define int long long
using namespace std;

long long tree[300010];
int lazy[300010];

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
int getSum(int n, int qs, int qe)
{
    return getSumUtil(0, n-1, qs, qe, 0);
}
void constructSTUtil(int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = 0;
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(ss, mid, si*2+1);
    constructSTUtil(mid+1, se, si*2+2);
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
void constructST(int n)
{
    constructSTUtil(0, n-1, 0);
}

main()
{
    //freopen("input.txt", "r", stdin);
    int t; cin>>t;
    while(t--)
    {
      memset(lazy, 0, sizeof lazy);
      memset(tree, 0, sizeof tree);
      int n, q;
      cin>>n>>q;
      //constructST(n);
      while(q--)
      {
        int sr; cin>>sr;
        if(sr == 0)
        {
          int l, r, val;
          cin>>l>>r>>val;
          updateRange(n, l-1, r-1, val);
        }
        else if(sr == 1)
        {
          int l, r;
          cin>>l>>r;
          cout<<getSum(n, l-1, r-1)<<endl;
        }
      }
    }
    /*
    for(int i = 0; i < n; i++)
      cout<<tree[i]<<" ";
    cout<<endl;
    */
}
