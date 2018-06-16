#include "session10_dcs.h"
#include<stdlib.h>

void DistributionCountingSorting(int *a,int n)
{
  int *s=(int *)malloc(n*sizeof(int));
  int i,u,l,j;
  u=a[0];
  l=a[0];
  for(i=0;i<n;i++)
  {
    if(a[i]<l)
     l=a[i];
    if(a[i]>u)
     u=a[i];
  }
  //printf("Max-min=%d\n",u-l);
  int *d=(int *)malloc((u-l+1)*sizeof(int));
  for(j=0;j<=(u-l);j++)
   d[j]=0;
  for(i=0;i<=n-1;i++)
   d[a[i]-l]=d[a[i]-l]+1;
  for(j=1;j<=u-l;j++)
  d[j]=d[j-1]+d[j];
  for(i=n-1;i>=0;i--)
   {
     j=a[i]-l;
     s[d[j]-1]=a[i];
     d[j]=d[j]-1;
   }
   for(i=0;i<n;i++)
    a[i]=s[i];
}

void MergeSort(int *a,int n)
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
void merge(int *a,int m,int n)
{
  int i=0;
  int j=m;
  int k=0;
  int *b;
  b=(int *)malloc(n*sizeof(int));
  while(i<m && j<n)
  {
    if(a[i]<=a[j])
    {
      b[k]=a[i];
      //b[k].id=a[i].id;
      i++;
    }
    else
    {
      b[k]=a[j];
      //b[k].id=a[j].id;
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
    b[temp_k]=a[x];
    //b[temp_k].value=a[x].value;
    temp_k++;
  }
}
  else
  {
    for(z=j;z<n,temp_k<n;z++)
    {
      b[temp_k]=a[z];
      //b[temp_k].id=a[z].id;
      temp_k++;
    }
  }
  for(x=0;x<n;x++)
  {
    a[x]=b[x];
    //a[x].id=b[x].id;
  }
}
