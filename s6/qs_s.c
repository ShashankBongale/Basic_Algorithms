#include "session6_quicksort.h"

void QuickSort(Data* A, int n)
{
  int s;
  if(n<=1)
   return;
  s=Partition(A,n);
  QuickSort(A,s);
  QuickSort(&A[s+1],n-s-1);
  return;
}

int Partition(Data * A, int n)
{
  int p=A[0].id;
  int i=1;
  int j=n-1;
  Data temp;
  while(i<=j)
  {
    while(i<=j && A[i].id<p)
     i++;
    while(i<=j && A[j].id>p)
     j--;
    if(i<j)
    {
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
      i++;
      j--;
    }
  }
  temp=A[0];
  A[0]=A[j];
  A[j]=temp;
  return j;
}
