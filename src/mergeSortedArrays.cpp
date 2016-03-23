/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
void charSwap(struct transaction *a, struct transaction *b);
int divideDate(struct transaction *a);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL) return NULL;
	int i, j;
	struct transaction *C;
	C = (struct transaction*)calloc((ALen + BLen), sizeof(struct transaction));
	for (i = 0; i < ALen; i++){
		C[i] = A[i];
	}
	for (i = 0; i < BLen; i++){
		C[ALen++] = B[i];
	}
	for (i = 0; i < ALen; i++){
		int a = divideDate(&C[i]);
		for (j = 0; j < ALen; j++){
			int b = divideDate(&C[j]);
			if (a>b){
				//printf("dsd");
				charSwap(&C[i], &C[j]);
			}
		}
	}
	for (i = 0, j = ALen - 1; i<j; i++, j--){
		//printf("%s %s\n",C[i].date,C[j].date);
		charSwap(&C[i], &C[j]);
	}

		//	charSwap(&C[2], &C[3]);
		return C;
}
		
void charSwap(struct transaction *a, struct transaction *b){

			struct transaction temp = *a;
			*a = *b;
			*b = temp;
		}
int divideDate(struct transaction *a){
	int n = 1000;
	int j;
	int c=0;
	for (j = 6; j<10; j++){
		//if (a[i].date[j] != '-')
			c = c + ((a[0].date[j]) - '0')*n;
		n = n / 10;
	}
	return c;
}