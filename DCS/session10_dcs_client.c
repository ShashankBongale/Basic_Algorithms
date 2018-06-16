#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"session10_dcs.h"

double time_elapsed(struct timespec *start, struct timespec *end);


int main()
{
	struct timespec start1,end1,start2,end2;
	int n,i;

	scanf("%d",&n);

	//int A[n],B[n];
	int *A=(int*)malloc(sizeof(int)*n);
	int *B=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		//printf("Hello");
		scanf("%d",&A[i]);
		B[i]=A[i];
	}

	clock_gettime(CLOCK_REALTIME, &start1);
	DistributionCountingSorting(A,n);
	clock_gettime(CLOCK_REALTIME, &end1);

	clock_gettime(CLOCK_REALTIME, &start2);
	MergeSort(B,n);
	clock_gettime(CLOCK_REALTIME, &end2);

	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}	 

	printf("%lf\n",time_elapsed(&start1,&end1));
	printf("%lf\n",time_elapsed(&start2,&end2));
	free(A);
	free(B);

	return 0;

}

double time_elapsed(struct timespec *start, struct timespec *end)
{
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}


