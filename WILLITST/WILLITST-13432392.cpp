#include <iostream>
using namespace std;

int main()
{
        long long int n;
        while(scanf("%lld",&n)!=EOF)
        {
                if((n&(n-1))==0)
                        printf("TAK\n");
                else
                        printf("NIE\n");
        }
        return 0;
}
