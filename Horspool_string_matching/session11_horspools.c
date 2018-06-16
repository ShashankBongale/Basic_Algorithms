//Header file for session11_horspools.c
#include<stdlib.h>
#include<string.h>
#include"session11_horspools.h"
//Search for the first occurrences each of t patterns in text
//Returns an array of 0-based indexes of the first occurrence of each pattern in the text.
//Returns -1 if pattern not found.
int *horspools_strmatch_patterns(char *text, char **patterns, int t){
	//printf("1 top\n");
	int i;
	int *a=(int *)malloc(sizeof(int)*t);
	for(i=0;i<t;i++)
	{
		//printf("1 mid\n");
		 a[i]=horspools_strmatch_pattern(text,patterns[i]);
	}
	return a;
}

//Search for the first occurrence of a pattern in text
//Returns 0-based indexe of the first occurrence of a pattern in the text.
//Returns -1 if pattern not found.
int horspools_strmatch_pattern(char *text, char *pattern){
	//printf("2 top\n");
	int *table,i,j,n,m;
	table=(int*)malloc(sizeof(int)*128);
	m=strlen(pattern);
	n=strlen(text);
	for(i=0;i<128;i++)
		table[i]=m;
	for(j=0;j<m-1;j++)
		table[pattern[j]]=m-1-j;
	i=m-1;
	while(i<n){
		//printf("2 mid\n");
		j=0;
		while(j<m && text[i-j]==pattern[m-1-j])
			j++;
		if(j==m)
			return i-(m-1);
		i+=table[text[i]];
	}
	return -1;
	
}
