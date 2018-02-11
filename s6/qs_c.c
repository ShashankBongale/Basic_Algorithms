#include<stdio.h>
#include<stdlib.h>
#include "session6_quicksort.h"
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
QuickSort(data,n);
//printf("Outside quicksort\n");

for(i=0;i<n;i++)
{
  printf("%d %d\n",data[i].id,data[i].value);
}
return 1;
}
