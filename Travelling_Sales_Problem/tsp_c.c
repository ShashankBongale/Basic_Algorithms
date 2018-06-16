#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "session4_tsp.h"
int main()
{
int n,i;
int **graph;
scanf(" %d",&n);
graph=(int **)malloc(n*sizeof(int *));
int j;
int k;
int temp_buf;
for(i=0;i<n;i++)
{
  graph[i]=(int *)malloc(n*sizeof(int));
  for(j=0;j<n;j++)
   {
     scanf(" %d",&temp_buf);
     graph[i][j]=temp_buf;
   }
}/*
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
   printf("%d ",graph[i][j]);
printf("\n");
}
*/
int cost;
cost=tsp(graph,n);
printf("%d\n",cost);
return 0;
} 	
