#include<stdio.h>
#include<stdlib.h>
#include "session7_sort1.h"

void Merge(Record* A, Record* L, Record* R, int nL, int nR);
int Partition(Record* A, int n);

void swap(Record* X, Record* Y);

long int InsertionSort(Record* A, int n)
{
	int i, j;
	long int count=0;
	Record temp;
	for(i=1;i<n;i++)
	{
		temp=A[i];
		j=i;
		while(j>0 && A[j-1].serialnumber>temp.serialnumber)
		{
			count++;
			A[j].serialnumber=A[j-1].serialnumber;
			j--;
		}
		A[j]=temp;
		if(j>0)
			count++;
	}
	return count;
}
long int BubbleSort(Record* A, int n)
{
	int i, j, noswap;
	long int count;
	for(i=0; i<=n-2; i++)
	{
		noswap=1;
		for(j=0; j<=n-2-i; j++)
		{
			count++;
			if(A[j].serialnumber > A[j+1].serialnumber)
			{
				swap(&A[j], &A[j+1]);
				noswap=0;
			}
		}
		if(noswap==1)
		{
			return count;
		}
	}
	return count;
}

long int SelectionSort(Record* A, int n)
{
	int i, j;
	long int count=0;
	for(i=0; i<=n-2; i++)
	{
		int min=i;
		for(j=i+1; j<=n-1; j++)
		{
			count++;
			if(A[j].serialnumber<A[min].serialnumber)
			{
				min=j;
			}
		}
		swap(&A[i], &A[min]);
	}
	return count;
}

long int count1=0;
long int MergeSort(Record* A, int n)
{
	if(n<2)
	{
		return count1;
	}
	int mid, i;
	mid=(int)(n/2);
	Record* left=(Record*)malloc(sizeof(Record)*mid);
	Record* right=(Record*)malloc(sizeof(Record)*(n-mid));
	for(i=0; i<mid; i++)
	{
		left[i].serialnumber=A[i].serialnumber;
		left[i].score=A[i].score;
	}
	for(i=mid; i<n; i++)
	{
		right[i-mid].serialnumber=A[i].serialnumber;
		right[i-mid].score=A[i].score;
	}
	MergeSort(left, mid);
	MergeSort(right, n-mid);Merge(A, left, right, mid, n-mid);	
	return count1;
}

void Merge(Record* A, Record* L, Record* R, int nL, int nR)
{
	int i=0, j=0, k=0;
	//long int count=0;
	while(i<nL && j<nR)
	{
		count1++;
		if(L[i].serialnumber<=R[j].serialnumber)
		{
			A[k].serialnumber=L[i].serialnumber;
			A[k].score=L[i].score;
			i++;
		}
		else
		{
			A[k].serialnumber=R[j].serialnumber;
			A[k].score=R[j].score;
			j++;
		}
		k++;
	}
	while(i<nL)
	{
		A[k].serialnumber=L[i].serialnumber;
		A[k].score=L[i].score;
		k++;
		i++;
	}
	while(j<nR)
	{
		A[k].serialnumber=R[j].serialnumber;
		A[k].score=R[j].score;
		k++;
		j++;
	}
	//return count;
}

long int count2=0;
long int QuickSort(Record* A, int n)
{
	if(n<=1)
		return count2;
	int pi=Partition(A,n);
	QuickSort(A, pi);
	QuickSort(A+pi+1, n-pi-1);
	return count2;
}

int Partition(Record* A, int n)
{
	int p=A[0].serialnumber, i=1, j=n-1;
	while(i<=j)
	{
		while(i<=j && A[i].serialnumber<p)
		{
			count2++;
			i++;
		}
		while(i<=j && A[j].serialnumber>p)
		{
			count2++;
			j--;
		}
		if(i<=j)
		{
			count2++;
		}
		if(i<j)
		{
			swap(&A[i], &A[j]);
			i++;
			j--;
		}
	}
	swap(&A[j], &A[0]);
	return j;
}

void swap(Record* X, Record* Y)
{
	Record temp;
	temp=*X;
	*X=*Y;
	*Y=temp;
}







