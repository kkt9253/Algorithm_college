#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void changeArray(int data[], int i, int n)
{
	int temp = data[i];
	data[i] = data[n];
	data[n] = temp;
}

void printFunction(int data[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", data[i]);
}

void push(int data[], int receiveIedex, int giveIedex)
{
	int pushValue = data[giveIedex];
	while (giveIedex != receiveIedex)
	{
		data[giveIedex] = data[giveIedex - 1];
		giveIedex--;
	}
	data[receiveIedex] = pushValue;
}

void insertionSort(int data[], int n) 
{
	if (n == 0)
		return;
	else
	{
		insertionSort(data, n - 1);
		for (int i = 0; i < n; i++)
		{
			if (data[i] > data[n - 1])
				push(data, i, n - 1);
		}
	}
}

int main() {
	int chooseData[] = { 8, 90, 48, 73, 31, 5, 29, 91, 11, 15 };
	insertionSort(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
	printFunction(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
}

/*
»ðÀÔ

#include <stdio.h>

void insertSort(int data[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = data[i];
		j = i - 1;

		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
	   data[j + 1] = key;
	}
}

void printArray(int data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");
}

// Driver code
int main()
{
	int data[] = {3,31,48,73,8,11,20,29,65,15};
	int n = sizeof(data) / sizeof(data[0]);

	insertSort(data, n);
	printArray(data, n);

	return 0;
}
*/