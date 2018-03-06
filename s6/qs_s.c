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
    while(i<=j && A[i].id<p)      //We shoud ensure that all elements less than pivot
     i++;                         //are on its left side
    while(i<=j && A[j].id>p)      //We shoud ensure that all elements greater than pivot
     j--;                         //are on its right side
    if(i<j)
    {
      temp=A[i];
      A[i]=A[j];               //Once the above condition fails and i and j have not crossed
      A[j]=temp;               //we swap the elements
      i++;
      j--;
    }
  }
  temp=A[0];                 //Outside for loop means i and j have crossed each other.
  A[0]=A[j];
  A[j]=temp;
  return j;
}
