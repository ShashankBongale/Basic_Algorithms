#include "session9_heapsort.h"
void HeapSort(Data *A,int n)
{
  HeapBottomUp(A,n);
  int j;
  Data temp;
  int i;
  for(i=n-1;i>=1;i--)
  {
    temp=A[0];
    A[0]=A[i];
    A[i]=temp;
    Heapify(A,0,i-1);
  }
}

void HeapBottomUp(Data *A,int n)
{
  int j1;
  if(n<=1)
   return;
  int i;
  for(i=(n/2)-1;i>=0;i--)
  {
   Heapify(A,i,n);
 }
}

void Heapify(Data *A,int k,int n)
{
  int j1;
  Data temp;
  int j;
  //printf("Heapify\n");
  if((2*k+1)>n)
   return;

  j=2*k+1;
  if(j+1<=n)
  {
    if(A[j+1].id>A[j].id)
     j=j+1;
  }
  if(A[j].id>A[k].id)
  {
    temp=A[j];
    A[j]=A[k];
    A[k]=temp;
    Heapify(A,j,n);
  }
}
