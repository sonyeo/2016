#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof(a[0]))

void PrintInt(int iData) {
	printf("%i,", iData);
}

void PrintInt2(int iData) {
	printf("%i\r\n", iData);
}

void PrintArray(int* p, int iArraySize, void(*fp)(int))
{
	for (int i = 0; i < iArraySize; ++i) {
		fp(p[i]);
	}//for
}

void main() {
	int a[] = { 1, 5, 3, 7, 9 };
	PrintArray(a, ARRAY_SIZE(a), PrintInt);
	printf("\r\n");
	PrintArray(a, ARRAY_SIZE(a), PrintInt2);
	/**
	1,5,3,7,9,
	1
	5
	3
	7
	9
	*/
}//main()
