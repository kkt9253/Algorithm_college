#include <stdio.h>
#define max 100

/*
#define MAX 5

void countingSort(int A[], int B[], int n)
{
	int C[MAX + 1] = { 0 };
	for (int i = 0; i <= MAX; i++)
		C[i] = 0; // C배열 초기화
	for (int j = 0; j < n; j++)
		C[A[j]]++; // C배열에 각 인덱스에 해당하는 갯수 넣음
	for (int i = 1; i <= MAX; i++)
		C[i] = C[i] + C[i - 1];
	for (int j = n - 1; j >= 0; j--)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

int main() {
	//int countingData[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	//int B[sizeof(countingData) / sizeof(countingData[0])];
	//countingSort(countingData, B, sizeof(countingData) / sizeof(countingData[0]));
	//printFunction(B, 8);
}
*/

void countingsort(int data[], int n) {

	int c[max];
	for (int i = 0; i < max; i++) {
		c[i] = 0; // 초기화 
	}

	for (int i = 0; i < n; i++) {
		int j = data[i];
		c[j]++; // 개수 세기 
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < c[i]; j++) {
			printf("%d ", i);
		}
	}
}

int main(void)
{
	int data[] = { 3,11,8,3,8,11,20,29,5,5 };
	int n = sizeof(data) / sizeof(data[0]);
	countingsort(data, n);


	return 0;
}