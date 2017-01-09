#include <bits/stdc++.h>
using namespace std;
int main (void)
{
  ios_base::sync_with_stdio(0);
  int t, n, m, k;
  cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;
    int ary[n];
    for(int i =0; i <n ; i++)
      cin>>ary[i];
    int xs = ary[0];
    sort(ary, ary + n);
    int indx;
    for(int i = 0; i < n; i++)
    {
      if(ary[i] == xs)
        indx = i;
    }
    int buff;
    for(int i = 0; i < n; i++)
    {
    buff = i;
    int x = ary[indx] + m;
    int ub = upper_bound(ary, ary+n, x)-ary-1;
    if(ary[ub] == ary[indx])
      break;
    ary[indx] = ary[ub];
    
    }
    int res = k*buff;
    cout<<ary[indx]<<" "<<res<<"\n";    
  }
}