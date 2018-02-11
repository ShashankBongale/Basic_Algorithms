#include<string.h>
#include<stdlib.h>
#include "session2_strmatch.h"
int *strmatch_patterns(char *text, char **patterns, int t)
{
  int *arr;
  arr=(int *)malloc(t*sizeof(int));
  int i;
  int v;
  for(i=0;i<t;i++)
  {
    v=strmatch_pattern(text,patterns[i]);
    arr[i]=v;
  }
  return arr;
}
int strmatch_pattern(char *text, char *pattern)
{
  int m,n;
  n=strlen(text);
  m=strlen(pattern);
  int i;
  int j;
  for(i=0;i<=n-m;i++)
  {
    
    for(j=0;j<m;j++)
    {
      if(pattern[j]!=text[i+j])
       break;
    }
    if(j==m)
     return i;
  }
  return -1;
}
