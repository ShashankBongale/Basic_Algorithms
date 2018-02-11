#include "session3_bubbleselection.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  scanf(" %d",&n);
  Data *d,*temp1;
  d=(Data *)malloc(sizeof(Data)*n);
  temp1=(Data *)malloc(sizeof(Data)*n);
  int i;
  int id,value;
  for(i=0;i<n;i++)
  {
    scanf(" %d %d",&id,&value);
    d[i].id=id;
    d[i].value=value;
    temp1[i].id=id;
    temp1[i].value=value;
  }
  int k;
  scanf(" %d",&k);
  Data *val;
  int temp=k;
  val=BubbleSort(d,n,k);
  for(i=0;i<n;i++)
   printf("%d %d\n",val[i].id,val[i].value);
  //printf("\n");
  for(i=0;i<n;i++)
   printf("%d %d\n",d[i].id,d[i].value);
  val=SelectionSort(temp1,n,k);
  for(i=0;i<n;i++)
   printf("%d %d\n",val[i].id,val[i].value);
  //printf("\n");
  for(i=0;i<n;i++)
   printf("%d %d\n",temp1[i].id,temp1[i].value);


  return 0;
}
