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

// p == front , r == back
void quickSort(int data[], int p, int r)
{
	if (p < r)
	{
		int q = pratition(data, p, r);
		quickSort(data, p, q - 1);
		quickSort(data, q + 1, r);
	}
}

int pratition(int data[], int p, int r)
{
	int pivot = data[r]; // 피봇값 == 끝값
	int i = p - 1;   // 피봇보다 작은 값들이 정렬 || 이미 정렬이 된 마지막 인덱스
	for (int j = p; j <= r; j++) // 비교되는 인덱스
	{
		if (data[j] < pivot)
		{
			i++;
			changeArray(data, i, j);
		}
	}
	changeArray(data, i + 1, r);
	return i + 1;
}

int main() {
	int data[] = { 31, 8, 48, 73, 11, 3, 20, 29, 65, 15 };
	quickSort(data, 0, (sizeof(data) / sizeof(data[0])-1));
	printFunction(data, sizeof(data) / sizeof(data[0]));
}

/*
 퀵

#include <stdio.h>

void swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int partition(int data[], int l, int r) {
    int center = (l + r) / 2;
    int pivot = data[center];

    while (l <= r) {
        while (data[l] < pivot) l++;
        while (data[r] > pivot) r--;

        if (l <= r) {
            swap(data, l, r);
            l++; r--;
        }
    }
    return l;
}

void quick_sort(int data[], int l, int r) {
    if (l < r) {
        int p = partition(data, l, r);

        quick_sort(data, l, p - 1);
        quick_sort(data, p, r);
    }
}

void quick_sort_(int data[], int size) {
    quick_sort(data, 0, size - 1);
}

//출력
void printArray(int data[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}

int main(void)
{
    int data[] = { 3,31,48,73,8,11,20,29,65,15 };
    int n = sizeof(data) / sizeof(data[0]);
   //Insertsort(data, n);
   // bubbleSort(data, n);
    quick_sort(data, 0, n-1);
    printArray(data, n);

    return 0;
}

*/