#include "session7_sort.h"
#include<stdlib.h>

long int InsertionSort(Record *A,int n)
{
  Record v;
  int i;
  int j;
  long int count=0;
  for(i=1;i<n;i++)
  {
    v=A[i];
    j=i-1;

    while(j>=0 && (++count && A[j].serialnumber>v.serialnumber))
    {
      //count++;
      A[j+1]=A[j];
      j=j-1;
    }
    //count++;
    A[j+1]=v;
  }
  return count;
}
long int BubbleSort(Record *A,int n)
{
  int j;n;
  //Data *temp2;
  //temp2=(Data *)malloc(n*sizeof(Data));
  int i;
  int temp;
  int flag;
  long int count1=0;
  int z;
  for(i=0;i<n-1;i++)
  {

    flag=0;
    for(j=0;j<n-i-1;j++)
    {
      //count1++;
      if(++count1 && A[j].serialnumber>A[j+1].serialnumber )
      {
        flag=1;
        temp=A[j].serialnumber;
        A[j].serialnumber=A[j+1].serialnumber;
        A[j+1].serialnumber=temp;
        temp=A[j].score;
        A[j].score=A[j+1].score;
        A[j+1].score=temp;
      }
    }
     if(flag==0)
      break;

  }
  return count1;
}
long int SelectionSort(Record *A,int n)
{
  int j,i;
  int min_index,temp;
  int z;
  long int cnt=0;
  for(i=0;i<n-1;i++)
  {
    //if()
    //count++;
    min_index=i;
    for(j=i+1;j<n;j++)
    {
      //cnt++;
      if(++cnt && A[min_index].serialnumber>A[j].serialnumber)
      {
        min_index=j;
      }
    }
    temp=A[min_index].serialnumber;
    A[min_index].serialnumber=A[i].serialnumber;
    A[i].serialnumber=temp;
    temp=A[min_index].score;
    A[min_index].score=A[i].score;
    A[i].score=temp;


  }
  return cnt;
}
long int MergeSort(Record* A, int n)
{
  //static long int cnt=0;
    int m;
    if(n<=1)
     return 0;
    m=n/2;
    //Mergesort(a,m);
    long int count=MergeSort(A,m);
    count=count+MergeSort(&A[m],n-m);
    count=count+merge(A,m,n);
    return count;
}
  long int merge(Record *a,int m,int n)
  {
    long int cnt=0;
    int i=0;
    int j=m;
    int k=0;
    Record *b;
    b=(Record *)malloc(n*sizeof(Record));
    while(i<m && j<n)
    {
      //cnt++;
      if(++cnt && a[i].serialnumber<=a[j].serialnumber)
      {
        b[k].serialnumber=a[i].serialnumber;
        b[k].score=a[i].score;
        i++;
      }
      else
      {
        b[k].serialnumber=a[j].serialnumber;
        b[k].score=a[j].score;
        j++;
      }
      k++;
    }
    int temp_k=k;
    int temp_i=i;
    int x,z;
    if(j==n)
  {
    for(x=i;x<m,temp_k<n;x++)
    {
      b[temp_k].score=a[x].score;
      b[temp_k].serialnumber=a[x].serialnumber;
      temp_k++;
    }
  }
    else
    {
      for(z=j;z<n,temp_k<n;z++)
      {
        b[temp_k].serialnumber=a[z].serialnumber;
        b[temp_k].score=a[z].score;
        temp_k++;
      }
    }
    for(x=0;x<n;x++)
    {
      a[x].serialnumber=b[x].serialnumber;
      a[x].score=b[x].score;
    }
   return cnt;
  }
  long int QuickSort(Record* A, int n)
  {
    int s;
    //static long int cnt=0;
    if(n<=1)
     return 0;
    long int count;
    median(A,n);
    count=0;
    s=Partition(A,n,&count);
    count=count+QuickSort(A,s);
    count=count+QuickSort(&A[s+1],n-s-1);
    return count;
  }

  int Partition(Record * A, int n,long int *cnt)
  {
    int p=A[0].serialnumber;
    int i=1;
    int j=n-1;
    Record temp;
    while(i<=j)
    {
      while(++(*cnt) && i<=j && A[i].serialnumber<p)
       i++;
      while(++(*cnt) && i<=j && A[j].serialnumber>=p)
       j--;
      if(i<j)
      {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
      }
    }
    temp=A[0];
    A[0]=A[j];
    A[j]=temp;
    return j;
  }
  void median(Record *A, int n)
  {
  	int l = 0;
  	int r = n-1;
  	int m = (l+r)/2;

  	int flag = 0;
  	Record temp;
  	if((A[l].serialnumber < A[m].serialnumber && A[m].serialnumber < A[r].serialnumber )||(A[r].serialnumber < A[m].serialnumber && A[m].serialnumber < A[l].serialnumber )){
  		temp = A[0];
  		A[0] = A[m];
  		A[m] = temp;
  		flag=1;
  	}
  	else if((A[l].serialnumber < A[r].serialnumber && A[r].serialnumber < A[m].serialnumber )||(A[m].serialnumber < A[r].serialnumber && A[r].serialnumber < A[l].serialnumber )){
  		temp = A[0];
  		A[0] = A[r];
  		A[r] = temp;
  	}

  }
