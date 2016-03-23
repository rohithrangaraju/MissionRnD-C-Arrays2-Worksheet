/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
int main(){
	int A [10]= { 1, 2, 4, 1, 2, 4, 1, 2, 4, 3 };
	int c = findSingleOccurenceNumber(A,10);
	printf("%d", c);
	getchar();
return 0;
}