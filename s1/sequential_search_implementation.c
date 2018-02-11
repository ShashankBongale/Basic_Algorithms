//this is the implementation in which we write the 
//the main function of our pgm
//Our function returns the index of the firt occurance
#include "sequential_search.h"
int sequential_search(int *a,int n,int k)
{
  int i;
  for(i=0;i<n;i++){
    if(a[i]==k)
     return i;
  }
  return -1;
}
