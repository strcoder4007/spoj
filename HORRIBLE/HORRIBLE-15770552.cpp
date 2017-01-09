#include<iostream>
 #include<cstdlib>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 #define int long long

long long segtree[300010];
long long lazy[300010];

void updatetree(int low, int high, int value, int qlow, int qhigh, int pos)
{
    if (lazy[pos] != 0)
    {
        segtree[pos] += (high-low+1)*lazy[pos];
        if (low != high)
        {
            lazy[pos*2 + 1]   += lazy[pos];
            lazy[pos*2 + 2]   += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (low>high|| low>qhigh || high<qlow)
        return ;
    if (low>=qlow && high<=qhigh)
    {
        segtree[pos] += value*(high-low+1);
        if (low != high)
        {
            lazy[2*pos+1]   += value;
            lazy[2*pos+2]   += value;
        }
        return;
    }
    int mid = (low+high)/2;
    updatetree(low, mid, value, qlow, qhigh, 2*pos+1);
    updatetree(mid+1, high, value, qlow, qhigh, 2*pos+2);
    segtree[pos] = segtree[2*pos+1] + segtree[2*pos+2];
}

int addtree(int low,int high,int qlow,int qhigh,int pos)
	{

	if(lazy[pos]!=0)
		{
		segtree[pos]+=(high-low+1)*lazy[pos];
		if(low!=high)
		 {
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		 }
		 lazy[pos]=0;
		}
	if(qlow>high || qhigh<low || high<low)
	  return 0;

 if(qlow<=low&&qhigh>=high)
		 return segtree[pos];

int mid=(low+high)/2;
return addtree(low,mid,qlow,qhigh,2*pos+1)+
addtree(mid+1,high,qlow,qhigh,2*pos+2);
	}

main()
			{
				///freopen("input.txt", "r", stdin);
				ios_base::sync_with_stdio(false);
				int t;  cin>>t;
				while(t--)
				{
					int n, c;
					cin>>n>>c;
					memset(lazy, 0, sizeof lazy);
					memset(segtree, 0, sizeof segtree);
			 		while(c--)
			 		{
						int b; cin>>b;
						if(b==0)
						{
							int p, q, v;
							cin>>p>>q>>v;
							updatetree(0,n-1, v, p-1, q-1, 0);
						}
						else
						{
							int p, q;
							cin>>p>>q;
							cout<<addtree(0,n-1,p-1,q-1,0)<<"\n";
						}
					}
				}
}
