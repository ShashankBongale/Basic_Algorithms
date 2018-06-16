#include<stdio.h>
#include<stdlib.h>

void dfs_recurse(int i, int n, int **adjacency_matrix, int *mark_array);

void bfs_node(int i, int n, int **adjacency_matrix, int *mark_array);

//here n is the number of vertices
//and adjacency matrix of order of n*n is representing a graph
int DFS_main(int n, int **adjacency_matrix)
{
	int *mark_array;
	int i;
	int count;
	
	mark_array = (int*)malloc(n*sizeof(int));
	count = 0;
	
	for(i=0; i<n; ++i)
		mark_array[i] = 0;
		
	for(i=0; i<n; ++i)
	{
		if(!mark_array[i])
		{
			dfs_recurse(i, n, adjacency_matrix, mark_array);
			++count;
		}
	}
	
	return count;
}

void dfs_recurse(int i, int n, int **adjacency_matrix, int *mark_array)
{
	int j;
	
	mark_array[i] = 1;
	
	for(j=0; j<n; ++j)
	{
		if(adjacency_matrix[i][j] && !mark_array[j])
			dfs_recurse(j, n, adjacency_matrix, mark_array);
	}
}

int BFS_main(int n, int **adjacency_matrix)
{
	int *mark_array;
	int i;
	int count;
	
	mark_array = (int*)malloc(n*sizeof(int));
	count = 0;
	
	for (i=0; i<n; ++i)
		mark_array[i] = 0;
	
	for (i=0; i<n; ++i)
	{
		if(!mark_array[i])
		{
			bfs_node(i, n, adjacency_matrix, mark_array);
			++count;
		}
	}
	
	return count;
}

void bfs_node(int i, int n, int **adjacency_matrix, int *mark_array)
{
	int *Queue;
	int back;
	
	Queue = (int *)malloc(sizeof(int)*n);
	back = -1;
	
	mark_array[i] = 1;
	Queue[++back] = i;
	
	while(back >= 0)
	{
		int front;
		int j;
		
		front = Queue[0];
		
		for(j=0; j<back; ++j)
			Queue[j] = Queue[j+1];
		
		--back;
		
		for(j=0; j<n; ++j)
		{
			if(adjacency_matrix[front][j] && !mark_array[j])
			{
				mark_array[j] = 1;
				Queue[++back] = j;
			}
		}
	}
}
