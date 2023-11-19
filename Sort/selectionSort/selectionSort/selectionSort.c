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

void selectionSort(int data[], int n)
{
	while (n != 0)
	{
		int high = 0;
		for (int i = 0; i < n; i++)
		{
			if (data[high] < data[i])
				high = i;
		}
		changeArray(data, high, n - 1);
		n--;
	}
}

int main() {
	int chooseData[] = { 8, 90, 48, 73, 31, 5, 29, 91, 11, 15 };
	selectionSort(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
	printFunction(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
}

/*
선택

#include <stdio.h>

void swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void selectSort(int data[], int size) {

    for (int i = 0; i < size; i++) {
        int min = i;

        for (int j = i; j < size; j++) {
            // 이전에 정렬된 부분 제외하고 i부터 끝까지

            if (data[j] < data[min]) {
                // 최소값을 찾았을 때

                min = j;
            }
        }

        swap(data, min, i);
    }
}
void printdataay(int data[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int main()
{
    int data[] = { 3,31,48,73,8,11,20,29,65,15 };
    int n = sizeof(data) / sizeof(data[0]);
    selectSort(data, n);
    printf("Sorted : \n");
    printdataay(data, n);
    return 0;
}
*/