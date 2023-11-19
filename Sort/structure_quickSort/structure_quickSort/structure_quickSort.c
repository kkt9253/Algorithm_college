#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define DAY 30

typedef struct {
	int date;
	int duration;
	int efficiency;
	char level[10];
} Fitbit_Daily_Info;

Fitbit_Daily_Info monthly_info[DAY + 1];

void printData() {
	for (int i = 1; i <= DAY; i++) {
		printf("[%d] Date:%d	Duration:%d		Efficienty:%d	Level:%s\n",
			i, monthly_info[i].date, monthly_info[i].duration,
			monthly_info[i].efficiency, monthly_info[i].level);
	}
}

int structure_pratition(Fitbit_Daily_Info A[], int p, int r)
{
	Fitbit_Daily_Info x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j].date < x.date) {
			i++;
			Fitbit_Daily_Info temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	Fitbit_Daily_Info temp1 = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp1;

	return i + 1;
}

void structure_quickSort(Fitbit_Daily_Info A[], int p, int r) {
	if (p < r) {
		int q = structure_pratition(A, p, r);
		structure_quickSort(A, p, q - 1);
		structure_quickSort(A, q + 1, r);
	}
}

int main() {
	freopen("fitbit_data.txt", "r", stdin);

	for (int i = 1; i <= DAY; i++) {   // 데이터 읽기
		scanf("%d", &monthly_info[i].date);
		scanf("%d", &monthly_info[i].duration);
		scanf("%d", &monthly_info[i].efficiency);
		scanf("%s", monthly_info[i].level);
	}

	structure_quickSort(monthly_info, 1, DAY);	// 입력 데이터에 대해 퀵정렬 수행
	printData();		// 퀵정렬 후 정렬된 데이터 출력
}