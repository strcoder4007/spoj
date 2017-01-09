#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;


int x,y;
bool MAP[20][20];
int solve(vector<int>steps)
{
    bool temp[x+1][y+1];
    memset(temp,0,sizeof temp);
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            temp[i][j]=MAP[i][j];
    int ans=0;
    for(int i=0; i<steps.size(); i++)
    {
        int t=steps[i];
        temp[0][t] = !temp[0][t];
        ans++;
        if(t+1<y)
            temp[0][t+1] = !temp[0][t+1];
        if(t>=1)
            temp[0][t-1] = !temp[0][t-1];
        if(1<x)
            temp[1][t] = !temp[1][t];
    }
    for(int i = 1; i < x; i++)
        for(int j = 0; j < y; j++)
            if(temp[i-1][j] == 1)
            {
                temp[i][j] = !temp[i][j];
                ans++;
                if(i-1>=0)
                    temp[i-1][j] = !temp[i-1][j];
                if(i+1<x)
                    temp[i+1][j] = !temp[i+1][j];
                if(j+1<y)
                    temp[i][j+1] = !temp[i][j+1];
                if(j-1>=0)
                    temp[i][j-1] = !temp[i][j-1];
            }

    bool found = false;
    for(int i=0; i<x && !found; i++)
        for(int j=0; j<y; j++)
            if(temp[i][j] == 1)
            {
                found = true;
                break;
            }
    if(found)
        return INT_MAX;
    else
        return ans;

}
int main()
{
    //freopen("input.txt", "r", stdin);
    char C;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(x==0 && y==0)
            break;
        memset(MAP,0,sizeof MAP);

        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
            {
                cin>>C;
                if(C=='X')
                    MAP[i][j]=true;
                else
                    MAP[i][j]=false ;
            }

        int ans=INT_MAX;
        for(int i=0; i<(1<<y); i++)
        {
            vector<int >steps;
            for(int j=0; j<y; j++)
                if(i &(1<<j))
                    steps.push_back(j);

            int num = solve(steps);
            ans=min(num,ans);

        }
        if(ans<INT_MAX)
            printf("You have to tap %d tiles.\n",ans);

        else
            printf("Damaged billboard.\n");


    }

   return 0;
}
