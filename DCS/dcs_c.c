#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "session10_dcs.h"
double time_elapsed(struct timespec *start,struct timespec *end);
int main()
{
  struct timespec start;
  struct timespec end;
  struct timespec mstart;
  struct timespec mend;
  int n;
  scanf(" %d",&n);
  int i;
  int *a=(int *)malloc(n*sizeof(int));
  int *b=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
   scanf(" %d",&a[i]);
   for(i=0;i<n;i++)
    b[i]=a[i];
  int *s;

  clock_gettime(CLOCK_REALTIME, &start);
  DistributionCountingSorting(a,n);
  clock_gettime(CLOCK_REALTIME, &end);
clock_gettime(CLOCK_REALTIME, &mstart);
  MergeSort(b,n);
clock_gettime(CLOCK_REALTIME, &mend);

  for(i=0;i<n;i++)
   printf("%d\n",a[i]);
  printf("DCS %lf\n",time_elapsed(&start, &end));
  printf("MS %lf\n",time_elapsed(&mstart, &mend));
  return 0;
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
