#include <bits/stdc++.h>
using namespace std;

int done[2010], degree[2010], adj[2010][2010];
int flag[2010];


int dfs(int node)
{

  done[node] = 1;
  int x = 1;
  for(int i = 0; i < degree[node]; i++)
  {
    if(flag[adj[node][i]] == -1)
    {
      flag[adj[node][i]] = !flag[node];
      x *= dfs(adj[node][i]);
    }
    else
    {
      if(flag[adj[node][i]]!=(!flag[node]))
      {
        x=0;
        break;
      }
    }
  }
  return x;
}

int main (void)
 {

   //freopen("F:/input.txt", "r", stdin);
   //freopen("F:/output.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
   int t;
   cin>>t;
   int xs = t;
   while(t--)
   {
       memset(flag, -1, sizeof(flag));
       memset(degree, 0, sizeof(degree));
       memset(done, 0, sizeof(done));
     int n, m;
     cin>>n>>m;
     for(int i = 0; i < m; i++)
     {
       int a, b;
       cin>>a>>b;
       adj[a][degree[a]] = b;
       degree[a]++;
       adj[b][degree[b]] = a;
       degree[b]++;
     }
     int i;
     for(i = 1; i <= n; i++)
     {
       if(done[i])
         continue;
       flag[i] = 0;
       if(dfs(i) == 0)
        break;
     }
       cout<<"Scenario #"<<xs-t<<":"<<endl;
     if(i > n)
     {
       cout<<"No suspicious bugs found!"<<endl;
     }
     else
       cout<<"Suspicious bugs found!"<<endl;
   }
 }
