#include "session3_bubbleselection.h"
#include<stdio.h>
#include<stdlib.h>
Data* BubbleSort(Data* A, int n, int k)
{
  int j;
  Data *temp2;
  temp2=(Data *)malloc(n*sizeof(Data));
  int i;
  int temp;
  int flag;
  int count=0;
  int z;
  for(i=0;i<n-1;i++)
  {

    if(count==k)
    {
      for(z=0;z<n;z++)
       {
         temp2[z].value=A[z].value;
         temp2[z].id=A[z].id;
       }
    }
    count++;
    flag=0;
    for(j=0;j<n-i-1;j++)
    {
      if(A[j].value>A[j+1].value)
      {
        flag=1;
        temp=A[j].value;
        A[j].value=A[j+1].value;
        A[j+1].value=temp;
        temp=A[j].id;
        A[j].id=A[j+1].id;
        A[j+1].id=temp;
      }
    }


     if(count==k)
     {
       for(z=0;z<n;z++)
        {
          temp2[z].value=A[z].value;
          temp2[z].id=A[z].id;
        }
     }
     if(flag==0)
      break;

  }
  if(count<k)
  {
    for(z=0;z<n;z++)
     {
       temp2[z].value=A[z].value;
       temp2[z].id=A[z].id;
     }
  }
/*
  for(z=0;z<n;z++)
       printf("%d %d\n",A[z].id,A[z].value);
  //printf("\n");*/

  return temp2;
}
Data* SelectionSort(Data * A, int n, int k)
{
  int j,i;
  int min_index,temp;
  Data *temp2;
  temp2=(Data *)malloc(n*sizeof(Data));
  int count,z;
  count=0;
  for(i=0;i<n-1;i++)
  {
    //if()
    if(count==k)
    {
      for(z=0;z<n;z++)
       {
         temp2[z].value=A[z].value;
         temp2[z].id=A[z].id;
       }
    }
    count++;
    min_index=i;
    for(j=i+1;j<n;j++)
    {
      if(A[min_index].value>A[j].value)
      {
        min_index=j;
      }
    }
    temp=A[min_index].value;
    A[min_index].value=A[i].value;
    A[i].value=temp;
    temp=A[min_index].id;
    A[min_index].id=A[i].id;
    A[i].id=temp;

    if(count==k)
    {
      for(z=0;z<n;z++)
       {
         temp2[z].value=A[z].value;
         temp2[z].id=A[z].id;
       }
    }

  }
  if(count<k)
   {
     for(z=0;z<n;z++)
      {
        temp2[z].value=A[z].value;
        temp2[z].id=A[z].id;
      }
  }
  /*for(z=0;z<n;z++)
       printf("%d %d\n",A[z].id,A[z].value);*/

  return temp2;
}
