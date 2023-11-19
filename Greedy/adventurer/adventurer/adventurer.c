#include <stdio.h>

void swap(int *fear, int a, int b) {
	int temp = fear[a];
	fear[a] = fear[b];
	fear[b] = temp;
}

int main() {
	int n = 0;
	int fear[1000] = { 0, };
	printf("모험가가 몇명인가요?");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		printf("%d번째 모험가의 공포도를 적어주세요.", i+1);
		scanf_s("%d", &fear[i]);
	}

	for (int i = 0; i < n; i++) // 정렬
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
	while (groupSize < n) // 배열의 값의 크기만큼 배열의 요소를 그룹으로 모음.(모일때마다 그룹+1), 안모이면 종료
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