#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "names.h"
int main()
{
  char **arr;
  int n;
  scanf("%d",&n);
  char *key;
  arr=(char **)malloc(n*sizeof(char *));
  char *temp;
  temp=(char *)malloc(1000000*sizeof(char));
  int i;
  for(i=0;i<n;i++){
    scanf(" %[^\n]",temp);
    arr[i]=(char *)malloc(1+strlen(temp)*sizeof(char));
    strcpy(arr[i],temp);
  }
  scanf(" %[^\n]",temp);
  key=(char *)malloc(1+strlen(temp)*sizeof(char));
  strcpy(key,temp);
  int v;
  v=search(arr,n,key);
  printf("%d\n",v);
  return 0;
}
