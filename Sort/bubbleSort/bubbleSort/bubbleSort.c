#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ������ ����� �ٸ��� «.

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


void bubbleSort(int data[], int n)
{
	if (n == 0)
		return;
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (data[i- 1] > data[i])
			{
				changeArray(data, i - 1, i);
			}
		}
	}
	bubbleSort(data, n - 1);
}

int main() {
	int chooseData[] = { 3,31,48,73,8,11,20,29,65,15 };
	bubbleSort(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
	printFunction(chooseData, sizeof(chooseData) / sizeof(chooseData[0]));
}

/*
����

#include <stdio.h>

//�� �ε��� ���� �ٲٴ� �Լ�
void swap(int data[], int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void bubbleSort(int data[], int n)
{
	// `n-1` ���
	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 0; i < n - 1 - k; i++)
		{
			if (data[i] > data[i + 1]) {
				swap(data, i, i + 1);
			}
		}

	}
}

//���
void printArray(int data[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
}

int main(void)
{
	int data[] = {3,31,48,73,8,11,20,29,65,15};
	int n = sizeof(data) / sizeof(data[0]);

	bubbleSort(data, n);
	printArray(data, n);
	return 0;
}
*/