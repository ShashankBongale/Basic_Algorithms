#include<stdio.h>
#include<stdlib.h>
#include "sequential_search.h"
int main()
{
  int *a;
  int n;
  int k;
  //printf("Enter number of elements\n");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  //printf("Enter elements\n");
  int i;
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  //printf("Enter key\n");
   scanf("%d",&k);
  int res;
  res=sequential_search(a,n,k);
/*
  if(res==-1)
   printf("Element not found\n");
  else
  printf("Element is present in the index %d\n",res);
*/
  printf("%d\n",res);
  return 0;
}
