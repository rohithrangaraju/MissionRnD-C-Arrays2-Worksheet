/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int Addi(int* AA, struct transaction *A, int k,int len);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL) return NULL;
	int i, j;
		int *Add = (int*)calloc((ALen+BLen), sizeof(int));
		int k = 0;
		k=Addi(Add, A, k,ALen);
		int len1 = k;
		k = Addi(Add, B, k,BLen);
		int count = 0;
		int a[10];
		int m = 0;
		if (ALen > BLen || ALen == BLen){
			for (i = 0; i < len1; i++){
				for (j = len1; j < k; j++){
					if (Add[i] == Add[j]){
						count++;
						a[m++] = i;
						break;
					}
				}
			}
		}
		else{
			for (i = len1; i < k; i++){
				for (j = 0; j < len1; j++){
					if (Add[i] == Add[j]){
						count++;
						a[m++] = i;
						break;
					}
				}
			}
		}
		if (count == 0) return NULL;
		free(Add);
		struct transaction *C;
		C = (struct transaction*)calloc(count, sizeof(struct transaction));
		for (i = 0; i<count; i++){
			C[i] = A[a[i]];
		}
		return C;
	}

int Addi(int* Add, struct transaction *C, int k,int len){
	int i, j, n;
	for (i = 0; i<len; i++){
		n = 10000000;
		for (j = 0; j<10; j++){
			if (C[i].date[j] == '-') continue;
			Add[k] = Add[k] + ((C[i].date[j]) - '0')*n;
			n = n / 10;
		}
		k++;
	}
	return k;
}