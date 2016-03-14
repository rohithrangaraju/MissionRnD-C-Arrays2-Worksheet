/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i,j,k=0,max=0,count=0,n=1000;
	for (i = 6; i < 10; i++){
		if (date[i] != '-')
		max = max+((date[i])-'0')*n;
		n = n / 10;
	}
	int *Add;
	Add = (int*)calloc(5, sizeof(int));
	for (i = 0; i<len; i++){
		n = 1000;
		for (j = 6; j<10; j++){
			if (Arr[i].date[j] != '-')
				Add[k] = Add[k] + ((Arr[i].date[j]) - '0')*n;
			n = n / 10;
		}
		k++;
	}
	for (i = 0; i < len; i++){
		if (max == Add[i]) count++;
	}
	if (count != 0){
		count = 0;
		for (i = 0; i < len; i++){
			if (max < Add[i])count++;
		}
		return count;
	}
	else
		return count;
}
