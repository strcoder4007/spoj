#include<iostream>
using namespace std;
int f(int  n)
{
    int count = 0;
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;
    return count;
}
int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        int i;
        cin>>i;
        cout<<f(i)<<endl;
    }
}
