#include<stdio.h>
int main()
{
    int a[100002],b[100002],n,tag,i,x;
    while(1)
    {
        tag=1;
        scanf("%d",&n);
    
        if (n==0)
            break;
    
        for (i=1;i<=n;i++)
        {
            scanf("%d",&x);
            a[i]=x;
            b[a[i]]=i;
        }    

        for (i=1;i<=n;i++)
            if (a[i]!=b[i])
            {
                tag=0;
                break;
            }
        if (tag==0)
            printf("not ambiguous\n");
        else    
            printf("ambiguous\n");
    }    
    return 0;
}