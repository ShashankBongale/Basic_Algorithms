#include "string_s.h"
#include<stdio.h>
int substring(char *text,char *pat,int n,int m)
{
  //printf("%s\n",text);
  //printf("%s\n",pat);
  //printf("%d\n",n);
  //printf("%d\n",m);
  int i;
  int j;
  for(i=0;i<=n-m;i++){
    j=0;
    for(j=0;j<m;j++){
      //printf("%d\n",j);
      if(text[i+j]!=pat[j])
       break;
     }
     if(j==m)
     {
      //printf("Inside if\n");
     return i;
    }
  }
  return -1;
}
