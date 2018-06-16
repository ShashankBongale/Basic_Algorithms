#include<stdlib.h>
#include<stdio.h>
#include "session4_tsp.h"
int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}
int tsp(int** graph, int n)
{
  int min_cost=10000000;
  int cost;
  int *perm;
  int i;
  perm=(int *)malloc(sizeof(int)*(n-1));

  int j=1;
  for(i=0;i<n-1;i++)
  {
    perm[i]=j;
    j++;
  }/*
  for(i=0;i<n-1;i++)
   printf(" %d\n",perm[i]);*/
  do
  {
    cost=graph[0][perm[0]];                //first edge
    cost=cost+graph[perm[n-2]][0];         //last edge
    //printf("Cost=%d",cost);
    for(i=0;i<=n-3;i++)
    {
      cost=cost+graph[perm[i]][perm[i+1]];
      //printf(" Cost=%d",cost);
		}
      if(cost<min_cost)
      {
       min_cost=cost;
       //printf(" %d\n",cost);

	}
}while(get_next_permutation(perm,n-1));
  return min_cost;
}
