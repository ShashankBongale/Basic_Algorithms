//client code for naive string matching

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h> //link with -lrt

#include"session11_horspools.h"
double time_elapsed(struct timespec *start, struct timespec *end);

int main(int argc, char const *argv[]) 
{
	struct timespec start;
	struct timespec end;
	char **pattern;
	char *buf;
	int i;
	buf=(char*)malloc(10000000*sizeof(char));
	int n;
	scanf(" %[^\n]s",buf);
	char *str;
	str=(char*)malloc((1+strlen(buf))*sizeof(char));
	strcpy(str,buf);
	free(buf);
	scanf("%d",&n);
	char *temp=(char*)malloc(10000000*sizeof(char));
	
	pattern = (char **) malloc(n * sizeof(char*));
	for( i=0;i<n;i++)
	{
		scanf(" %[^\n]s",temp);
	pattern[i]=(char*)malloc((+strlen(temp))*sizeof(char));
		strcpy(pattern[i],temp);
	}
	free(temp);
	
	clock_gettime(CLOCK_REALTIME, &start); //start timestamp
	int *arr = horspools_strmatch_patterns(str, pattern, n); //to get the first occurrence of key in arr
	clock_gettime(CLOCK_REALTIME, &end); //end timestamp

	for(i = 0; i < n; ++i){
		printf("%d ", arr[i]);
		printf("\n");
	}
	
	printf("%lf sec\n", time_elapsed(&start, &end));
	for (i = 0; i < n; ++i) {
		free(pattern[i]);
	}
	free(pattern);
	free(str);
}
//returns the duration from start to end times in sec
double time_elapsed(struct timespec *start, struct timespec *end)
 {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in  nanoseconds
	return t;
}


