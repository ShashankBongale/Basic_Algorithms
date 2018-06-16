#include "session9_heapsort.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  scanf(" %d",&n);
  Data *A;
  A=(Data *)malloc((n+1)*sizeof(Data));
  int i;
  //A[0].id=0;
  //A[0].value=0;
  for(i=0;i<n;i++)
   scanf(" %d %d",&A[i].id,&A[i].value);
  HeapSort(A,n);
  for(i=0;i<n;i++)
   printf("%d %d\n",A[i].id,A[i].value);
  return 0;
}
