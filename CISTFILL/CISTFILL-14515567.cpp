#include <bits/stdc++.h>
#define GI GETNUM()
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define p_b push_back
#define ALL(ar) ar.begin(),ar.end()
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define VI vector<int>
#define VS vector<string>
#define VN vector<node>
#define PII pair<int,int>
#define SI set<int>
#define SN set<node>
#define EACH(x,a) for(typeof(a.begin()) x(a.begin());x!=a.end();x++)
typedef long long int LL;
struct node{
  int base,ht,area;
};
struct node v[50001];
#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int
      i ;

   ITYPE
      j ;

   i = GETCHAR () ;
   while ( ! DIG( i ) )
      i = GETCHAR () ;

   j = ( i - '0' ) ;

   i = GETCHAR () ;
   while ( DIG( i ) )
   {
      j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
      i = GETCHAR () ;
   }
   return ( j ) ;
}

int cnt;
int volume;
int maxht;
int loht = 1<<30;

void go()
{
     register double hi= maxht,mid,curr_volume;
     double lo=loht;
     int i=0;
     while( hi-lo >= 1e-3 )
     {
       mid = (lo + hi)/2;
       curr_volume = 0;
       for(i = 0; i < cnt; i++)
         if(mid - v[i].base >= 0)
         {
          if(v[i].ht < mid-v[i].base)
            curr_volume += v[i].area*v[i].ht;
          else
            curr_volume +=  v[i].area*(mid - v[i].base);
         }
       ((curr_volume>=volume)?hi:lo) = mid;
     }
     printf("%.2lf\n",hi);
}
int main()
{
  //freopen("/tmp/input.txt", "r", stdin);
  int t = GI ;
  while ( t-- )
  {
    int n = GI ;cnt = n;
    int a,b,c,d;
    int net_volume = 0 ;
    maxht = 0;
    int i = 0;
    for(i = 0; i < n; i++)
    {
      a = GI;b = GI;c = GI;d = GI;
      v[i].base = a;
      v[i].ht = b;
      v[i].area = c*d;
      net_volume += b*c*d;
      if(( a + b ) > maxht)
        maxht = a + b;
      if( a < loht )
        loht = a;
    }
    volume = GI;
    if(volume > net_volume)
      printf("OVERFLOW\n");
    else go();
  }
  return(0);
}
