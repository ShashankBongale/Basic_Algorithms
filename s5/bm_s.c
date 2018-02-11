#include "session5_mergesort_binsearch.h"
#include<stdlib.h>
void MergeSort(Data *a,int n)
{
  int m;
  if(n<=1)
   return;
  m=n/2;
  //Mergesort(a,m);
  MergeSort(a,m);
  MergeSort(&a[m],n-m);
  merge(a,m,n);
}
void merge(Data *a,int m,int n)
{
  int i=0;
  int j=m;
  int k=0;
  Data *b;
  b=(Data *)malloc(n*sizeof(Data));
  while(i<m && j<n)
  {
    if(a[i].value<=a[j].value)
    {
      b[k].value=a[i].value;
      b[k].id=a[i].id;
      i++;
    }
    else
    {
      b[k].value=a[j].value;
      b[k].id=a[j].id;
      j++;
    }
    k++;
  }
  int temp_k=k;
  int temp_i=i;
  int x,z;
  if(j==n)
{
  for(x=i;x<m,temp_k<n;x++)
  {
    b[temp_k].id=a[x].id;
    b[temp_k].value=a[x].value;
    temp_k++;
  }
}
  else
  {
    for(z=j;z<n,temp_k<n;z++)
    {
      b[temp_k].value=a[z].value;
      b[temp_k].id=a[z].id;
      temp_k++;
    }
  }
  for(x=0;x<n;x++)
  {
    a[x].value=b[x].value;
    a[x].id=b[x].id;
  }
}
int BinarySearch(Data *a,int n,int k)
{
  int l=0;
  int r=n-1;
int mid=(l+r)/2;
while(l<r)
{
  if(a[mid].value==k)
   return mid;
  else if(k>a[mid].value)
   l=mid+1;
  else if(k<a[mid].value)
   r=mid-1;

  mid=(r+l)/2;
}
return -1;
}
