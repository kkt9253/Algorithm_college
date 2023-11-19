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
	for (int i = 0; i < DAY; i++) {
		printf("[%d] Date:%d	Duration:%d		Efficienty:%d	Level:%s\n",
			i+1, monthly_info[i].date, monthly_info[i].duration,
			monthly_info[i].efficiency, monthly_info[i].level);
	}
}

void structure_changeArray(Fitbit_Daily_Info data_A[], Fitbit_Daily_Info data_B[])
{
	Fitbit_Daily_Info temp = *data_A;
	*data_A = *data_B;
	*data_B = temp;
}

void structure_bubbleSort(Fitbit_Daily_Info data[], int n)
{
	if (n == 1)
		return;
	else
	{
		structure_bubbleSort(data, n - 1);
		for (int i = 0; i < n; i++)
		{
			if (data[n - 1].date > data[i].date)
			{
				structure_changeArray(&data[i], &data[n - 1]);
			}
		}
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

	structure_bubbleSort(monthly_info, DAY + 1);	// 입력 데이터에 대해 퀵정렬 수행
	printData();		// 퀵정렬 후 정렬된 데이터 출력
}