#include <stdio.h>
#include <stdlib.h>
#include "session12_WarshallsFloyds.h"
#include <time.h>

double time_elapsed(struct timespec *start, struct timespec *end);

int main(int argc, char const *argv[])
{
    int n1, n2, i, j;
    int res;
    scanf("%d", &n1);
    int *arr_warshall[n1];
    struct timespec start;
    struct timespec end;

    double time1, time2;

    for (i = 0; i < n1; i++)
    {
        arr_warshall[i] = (int *)malloc(n1 * sizeof(int));
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &arr_warshall[i][j]);
        }
    }

    scanf("%d", &n2);
    int *arr_floyd[n2];

    for (i = 0; i < n2; i++)
    {
        arr_floyd[i] = (int *)malloc(n2 * sizeof(int));
    }

    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf("%d", &arr_floyd[i][j]);
        }
    }


    clock_gettime(CLOCK_REALTIME, &start);
    transitive_closure_warshalls(arr_warshall, n1);
    clock_gettime(CLOCK_REALTIME, &end);
    time1 = time_elapsed(&start, &end);

    clock_gettime(CLOCK_REALTIME, &start);
    all_pairs_shortest_path_distances_floyds(arr_floyd, n1);
    clock_gettime(CLOCK_REALTIME, &end);
    time2 = time_elapsed(&start, &end);



    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            printf("%d ", arr_warshall[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d ", arr_floyd[i][j]);
        }
        printf("\n");
    }


    printf("%lf seconds.\n",time1);
    printf("%lf seconds.\n",time2);
}

double time_elapsed(struct timespec *start, struct timespec *end)
{
    double t;
    //tv_sec has the time elasped in seconds
    t = (end->tv_sec - start->tv_sec);
    //tv_nsec has the time elasped in nano seconds
    //Final time will be precise with nano seconds
    t += ((end->tv_nsec - start->tv_nsec) * 0.000000001);
    return t;
}
