#include<string.h>
#include<stdio.h>
#include "names.h"
int search(char **arr,int n,char *key){
  int i;
  //printf("key=%s\n",key);
  for(i=0;i<n;i++)
  {
    //printf("%s\n",arr[i]);
    if(!strcmp(arr[i],key))
    {
     //printf("%d\n",i);
     return i;
   }
  }
  return -1;
}
