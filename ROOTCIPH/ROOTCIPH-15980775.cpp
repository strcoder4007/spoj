
#include <bits/stdc++.h>

long long int a,b,c,d;
int t,i;

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    for (i = 0 ; i < t ; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        d = (a*a) - (2*b);
        printf("%lld\n",d);
    }
    return 0;
}
