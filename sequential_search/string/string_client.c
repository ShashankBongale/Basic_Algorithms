#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "string_s.h"
int main()
{
  int i;
  int val;
  printf("Enter size of Original string\n");
  int n;
  scanf("%d",&n);
  printf("Enter size of pattern\n");
  int m;
  scanf("%d",&m);
  char *text,*pat,*buf;
  text=(char *)malloc(n*sizeof(char));
  pat=(char *)malloc(m*sizeof(char));
  buf=(char *)malloc(1000000*sizeof(char));
  printf("Enter first string\n");
  scanf(" %[^\n]",buf);
  strcpy(text,buf);
  printf("Enter pattern string\n");
  scanf(" %[^\n]",buf);
  strcpy(pat,buf);
  int value;
  value=substring(text,pat,n,m);
  printf("%d\n",value);
  return 0;
}
