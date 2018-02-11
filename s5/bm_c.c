#include<stdio.h>
#include<stdlib.h>
#include "session5_mergesort_binsearch.h"
int main()
{
Data *data;
int n;
int i;
scanf(" %d",&n);
data=(Data *)malloc(n*sizeof(Data));
for(i=0;i<n;i++)
{
  scanf(" %d %d",&data[i].id,&data[i].value);
}
MergeSort(data,n);

for(i=0;i<n;i++)
{
  printf("%d %d\n",data[i].id,data[i].value);
}
int index;
int key;

scanf("%d",&key);
//printf("%d\n",key);

index=BinarySearch(data,n,key);
if(index==-1)
 printf("NOT FOUND");
else
printf("%d %d %d\n",index,data[index].id,data[index].value);
return 1;
}
