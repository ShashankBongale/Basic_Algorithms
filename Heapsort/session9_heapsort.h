//Header file for session9_heapsort.c

typedef struct Data {
	int id;
	int value;
} Data;

//Heap Sort
//Use Heap Sort algorithm to sort the array an of records by their id.
void HeapSort(Data* A, int n);

//Construction of Heap from Bottom-up
void HeapBottomUp(Data * A, int n);

//To heapify the given element
void Heapify(Data *A,int k,int n);
