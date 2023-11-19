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

void structure_changeArray(Fitbit_Daily_Info data_A[], Fitbit_Daily_Info data_B[])
{
	Fitbit_Daily_Info temp = *data_A;
	*data_A = *data_B;
	*data_B = temp;
}

void structure_selectionSort(Fitbit_Daily_Info data[], int n)
{
	while (n != 0)
	{
		int high = 0;
		for (int i = 0; i < n; i++)
		{
			if (data[high].date < data[i].date)
				high = i;
		}
		structure_changeArray(&data[high], &data[n - 1]);
		n--;
	}
}

int main() {
	freopen("fitbit_data.txt", "r", stdin);

	for (int i = 1; i <= DAY; i++) {   // ������ �б�
		scanf("%d", &monthly_info[i].date);
		scanf("%d", &monthly_info[i].duration);
		scanf("%d", &monthly_info[i].efficiency);
		scanf("%s", monthly_info[i].level);
	}

	structure_selectionSort(monthly_info, DAY+1);	// �Է� �����Ϳ� ���� ������ ����
	printData();		// ������ �� ���ĵ� ������ ���
}