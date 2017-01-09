#include<iostream>
using namespace std;
int main()
{
    int n;
    while(1)
    {
            cin>>n;
            if(n==-1)
                     break;
            if(n==1)
                    cout<<"Y"<<endl;
            else
            {
                n=n-1;
                int i=1;
                while(n>0)
                {
                          n=n-(6*i);
                          i++;
                }
                if(n==0)
                        cout<<"Y"<<endl;
                else
                    cout<<"N"<<endl;
            }
    }
    return 0;
}