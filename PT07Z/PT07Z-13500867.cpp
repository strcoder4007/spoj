#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=10005;
int path[N],n,d[N];
vector<int> ans;
vector<int> graph[N];
queue< pair< int, int > > q;
bool mark[N];
void makefalse()
{
	for(int i=0;i<=n+1;i++)
		mark[i]=false;
}
void makezero()
{
	for(int i=0;i<=n+1;i++)
		d[i]=0;
}
void BFS(int x,bool p)
{
	int c,i,b;
	makefalse();
	makezero();
	q.push(make_pair(x,0));
	mark[x]=true;
	while(!q.empty())
	{
		b=q.front().first;
		for(i=0;i<graph[b].size();i++)
		{
			c=graph[b][i];
			if(mark[c]==false)
			{
				if(p)
				{
					path[c]=b;
				}
				d[c]=q.front().second+1;
				mark[c]=true;
				q.push(make_pair(c,d[c]));
			}
		}
		q.pop();
	}
}
int main()
{
	int i,j,c,x,xi,y,yi,pathlen,e,f;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&c,&e);
		graph[c].push_back(e);
		graph[e].push_back(c);
	}
	if(n==2)
	{
		printf("1 2");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(graph[i].size()==1)
		{
			BFS(i,false);
			break;
		}
	}
	x=d[1];
	xi=1;
	for(i=1;i<=n;i++)
		if(d[i]>x)
		{
			x=d[i];
			xi=i;
		}
	BFS(xi,true);
	yi=1;
	y=d[1];
	for(i=1;i<=n;i++)
		if(d[i]>y)
		{
			y=d[i];
			yi=i;
		}
	c=yi;
	pathlen=0;
	while(c!=xi)
	{
		c=path[c];
		pathlen++;
	}
	printf("%d",pathlen);
	return 0;
}



