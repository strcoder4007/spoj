#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

bool cmp( int a, int b ) 
{
   return a > b;
}

#define MOD 1000000007
#define PI 3.141592654
#define TRUE 1
#define FALSE 0
#define LL long long int

using namespace std;

int main()
{
        int T;
        cin>>T;
        while(T--)
        {
                LL a3,an3,sum,d,n,a;
                cin>>a3>>an3>>sum;
                n = (2*sum)/(a3+an3);
                d = (an3-a3)/(n-5);
                a = a3-(2*d);
                cout<<n<<endl;
                for(int i=0;i<n;i++)
                        cout<<(a+(i*d))<<" ";
                cout<<endl;
        }
        return 0;
}