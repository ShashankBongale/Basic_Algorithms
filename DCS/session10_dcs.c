#include<stdio.h>
#include"session10_dcs.h"
#include<stdlib.h>
void Merge(int *A,int m,int n);

void MergeSort(int* A, int n)
{
	if(n<=1)
		return;
	int m=n/2;
	MergeSort(A,m);
	MergeSort(A+m,n-m);
	Merge(A,m,n);
}
void Merge(int *A,int m,int n)
{
	int i=0,j=m,k=0;
	int B[n];
	while(i<m && j<n)
	{
		if(A[i]<=A[j])
		{
			B[k]=A[i];
			i++;
		}
		else
		{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	int index;
	if(j==n)
		for(index=i;index<m;index++,k++)
			B[k]=A[index];
	else
		for(index=j;index<n;index++,k++)
			B[k]=A[index];

	for(index=0;index<n;index++)
		{
			A[index]=B[index];
		}
}


int maxi(int *A,int n)
{
	int i;
	int max=A[0];
	for(i=1;i<n;i++)
		if(A[i]>max)
			max=A[i];
	return max;
}
int mini(int *A,int n)
{
	int i;
	int min=A[0];
	for(i=1;i<n;i++)
		if(A[i]<min)
			min=A[i];
	return min;
}
void DistributionCountingSorting(int* A, int n)
{
	int *temp;
	temp=(int *)malloc(n*sizeof(int));
	int i=0,j;
	int max=maxi(A,n);
	int min=mini(A,n);
	int *D;
	D=(int *)malloc((max-min+1)*sizeof(int));
	//printf("%d %d\n",max,min);
	for(j=0;j<=max-min;j++)
		D[j]=0;
	
	for(i=0;i<n;i++)
		D[A[i]-min]++;
	
	for(j=1;j<=max-min;j++)
		D[j]=D[j-1]+D[j];
	
	for(i=n-1;i>=0;i--)
	{
		j=A[i]-min;
		temp[D[j]-1]=A[i];
		D[j]--;
	}
	for(i=0;i<n;i++)
		A[i]=temp[i];
	
	free(temp);
	free(D);
}

