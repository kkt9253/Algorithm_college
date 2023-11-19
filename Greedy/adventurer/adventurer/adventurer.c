#include <stdio.h>

void swap(int *fear, int a, int b) {
	int temp = fear[a];
	fear[a] = fear[b];
	fear[b] = temp;
}

int main() {
	int n = 0;
	int fear[1000] = { 0, };
	printf("���谡�� ����ΰ���?");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		printf("%d��° ���谡�� �������� �����ּ���.", i+1);
		scanf_s("%d", &fear[i]);
	}

	for (int i = 0; i < n; i++) // ����
	{
		for (int j = 0; j < n-1; j++)
		{
			if (fear[j] > fear[j + 1])
				swap(fear, j, j+1);
		}
	}
	int groupCount = 0;
	int groupSize = 0; 
	int currentIndex = 0;
	while (groupSize < n) // �迭�� ���� ũ�⸸ŭ �迭�� ��Ҹ� �׷����� ����.(���϶����� �׷�+1), �ȸ��̸� ����
	{
		currentIndex = groupSize;
		groupSize = (fear[groupSize] + currentIndex);
		if (groupSize < n) {
			groupCount++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", fear[i]);
	}
	printf("\n\n%d", groupCount);
}