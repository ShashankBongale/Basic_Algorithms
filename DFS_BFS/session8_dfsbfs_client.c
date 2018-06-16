#include<stdio.h>
#include <stdlib.h>
#include "session8_dfsbfs.h"

int main(int argc, char const *argv[])
{
	int no_test_cases;
	scanf("%d", &no_test_cases);
	for (int t = 0; t < no_test_cases; ++t)
	{
		int n;
		scanf("%d", &n);
		int **adjacency_matrix = (int **)malloc(sizeof(int *)*n);
		int i;
		int count_dfs, count_bfs;
		for (i = 0; i < n; ++i)
		{
			int *row = (int *)malloc(sizeof(int)*n);
			adjacency_matrix[i] = row;
		}
		for (i = 0; i < n; ++i)
		{
			int j;
			for(j = 0; j < n; j++)
			{
				scanf("%d", &(adjacency_matrix[i][j]));
			}
		}
		count_dfs = DFS_main(n, adjacency_matrix);
		count_bfs = BFS_main(n, adjacency_matrix);
		printf("%d\n", count_dfs);
		//printf("%d\n", count_bfs);
	}
	return 0;
}
