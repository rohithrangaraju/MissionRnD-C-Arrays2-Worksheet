/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
void qsort(int* A, int first, int last);
int sum(int x, int y, int z){
	int n = 0;
	n = x + y + z;
	return n;
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A==nullptr) return -1;
	qsort(A, 0, len - 1);
	int i;
	int x = 0;
	
		x = A[0]+A[1]+A[2];
	//printf("%d",x);
	i = 0;
	while (x / A[i] == 3){
		i = i + 3;
		x = sum(A[i], A[i + 1], A[i + 2]);
		//i++;
	}
	return A[i];
}
void qsort(int *A, int first, int last)
{
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;
		while (i<j)
		{
			while (A[i] <= A[pivot] && i<last)
				i++;
			while (A[j]>A[pivot])
				j--;
			if (i<j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[pivot];
		A[pivot] = A[j];
		A[j] = temp;
		qsort(A, first, j - 1);
		qsort(A, j + 1, last);
	}
}