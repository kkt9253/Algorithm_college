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

void push(Fitbit_Daily_Info data[], int receiveIedex, int giveIedex)
{
	Fitbit_Daily_Info temp = data[giveIedex];
	while (giveIedex != receiveIedex)
	{
		data[giveIedex] = data[giveIedex - 1];
		giveIedex--;
	}
	data[receiveIedex] = temp;
}

void structure_insertionSort(Fitbit_Daily_Info data[], int n)
{
	if (n == 1)
		return;
	else
	{
		structure_insertionSort(data, n - 1);
		for (int i = 0; i < n; i++)
		{
			if (data[i].date > data[n - 1].date)
				push(data, i, n - 1);
		}
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

	structure_insertionSort(monthly_info, DAY + 1);	// �Է� �����Ϳ� ���� ������ ����
	printData();		// ������ �� ���ĵ� ������ ���
}