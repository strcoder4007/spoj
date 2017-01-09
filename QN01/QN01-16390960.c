
#include <stdio.h>
int A[1001];
int main(){
  int i,j,k,n,x,y;
  scanf("%d",&n);
  A[0]=0;
  for(i=0;i<n;i++){
    scanf("%d",&j);
    A[i+1]=A[i]^j;
  }
  k = 0;
  for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
      if( (A[j]^A[i-1]) > k ){
	k = A[j]^A[i-1];
	x = i;
	y = j;
      }
    }
  }
  printf("%d\n%d %d\n",k,x,y);
  return 0;
}