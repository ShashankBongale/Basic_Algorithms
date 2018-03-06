#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "session7_sort.h"
double time_elapsed(struct timespec *start,struct timespec *end);
int main()
{
struct timespec start;
struct timespec end;
//Bubble Sort, Selection Sort, Merge Sort and Quick Sort algorithms.
Record *data;
Record *data_selection;
Record *data_bubble;
Record *data_merge;
Record *data_quick;
int n;
int i;
scanf(" %d",&n);
data=(Record *)malloc(n*sizeof(Record));
data_selection=(Record *)malloc(n*sizeof(Record));
data_bubble=(Record *)malloc(n*sizeof(Record));
data_merge=(Record *)malloc(n*sizeof(Record));
data_quick=(Record *)malloc(n*sizeof(Record));
for(i=0;i<n;i++)
{
  scanf(" %ld %d",&data[i].serialnumber,&data[i].score);
}
for(i=0;i<n;i++)
{
  data_selection[i]=data_bubble[i]=data_merge[i]=data_quick[i]=data[i];
}
long int count;
clock_gettime(CLOCK_REALTIME, &start);
count=InsertionSort(data,n);
clock_gettime(CLOCK_REALTIME, &end);
printf("Insertion Sort:%ld %lf\n",count,time_elapsed(&start, &end));
struct timespec start1;
struct timespec end1;
clock_gettime(CLOCK_REALTIME, &start1);
count=SelectionSort(data_selection,n);
clock_gettime(CLOCK_REALTIME, &end1);
printf("Selection Sort:%ld %lf\n",count,time_elapsed(&start1, &end1));
struct timespec start2;
struct timespec end2;
clock_gettime(CLOCK_REALTIME, &start2);
count=BubbleSort(data_bubble,n);
clock_gettime(CLOCK_REALTIME, &end2);
printf("Bubble Sort:%ld %lf\n",count,time_elapsed(&start2, &end2));
struct timespec start3;
struct timespec end3;
clock_gettime(CLOCK_REALTIME, &start3);
count=MergeSort(data_merge,n);
clock_gettime(CLOCK_REALTIME, &end3);
printf("Merge Sort:%ld %lf\n",count,time_elapsed(&start3, &end3));
struct timespec start4;
struct timespec end4;
clock_gettime(CLOCK_REALTIME, &start4);
count=QuickSort(data_quick,n);
clock_gettime(CLOCK_REALTIME, &end4);
printf("Quick Sort:%ld %lf\n",count,time_elapsed(&start4, &end4));
return 1;
}



double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
