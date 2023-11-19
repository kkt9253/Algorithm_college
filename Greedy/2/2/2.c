#include <stdio.h>
#include <stdlib.h>

struct product {
	double weight;
	double cost;
	double value;
};

void printFunction(struct product data[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%lf  ", data[i].value);
}

void changeArray(struct product* p, int i, int n)
{
	struct product temp = p[i];
	p[i] = p[n];
	p[n] = temp;
}

void bubbleSort(struct product* p, int data[], int n)
{
	if (n == 0)
		return;
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (data[i - 1] > data[i])
			{
				changeArray(p, i - 1, i);
			}
		}
	}
	bubbleSort(p, data, n - 1);
}

void quickSort(struct product data[], int p, int r)
{
	if (p < r)
	{
		int q = pratition(data, p, r);
		quickSort(data, p, q - 1);
		quickSort(data, q + 1, r);
	}
}

int pratition(struct product data[], int p, int r)
{
	double pivot = data[r].value; // 피봇값 == 끝값
	int i = p - 1;   // 피봇보다 작은 값들이 정렬 || 이미 정렬이 된 마지막 인덱스
	for (int j = p; j <= r; j++) // 비교되는 인덱스
	{
		if (data[j].value > pivot)
		{
			i++;
			changeArray(data, i, j);
		}
	}
	changeArray(data, i + 1, r);
	return i + 1;
}

int FractionalKnapsack(struct product *p, int count, int bagWeight) {
	double value_Sum = 0;
	double currentBagWeight = 0;
	int bag_List[1000] = { 0, };
	int i = 0;
	struct product S = p[i];

	while (currentBagWeight + p[i].weight <= bagWeight) {
		bag_List[i] = i+1; // 가방 물건 리스트에 담음.
		currentBagWeight += p[i].weight; // 가방에 광물 무게 담기
		value_Sum += p[i].cost; // 가방에 광물 가격 합 넣기
		S = p[++i]; // 그다음 광물로 바꿈
	}

	if (bagWeight - currentBagWeight > 0) {
		bag_List[i] = i + 1;
		value_Sum += p[i].value * (bagWeight - currentBagWeight);
	}
	printf("가방에 담긴 가치의 합은 %lf / ", value_Sum);
	for (int j = 0; j < count; j++) {
		printf("담긴 리스트는 %d ", bag_List[j]);
	}
	printf("이다.");

}

int main() {
	int bagWeight = 0;
	printf("가방의 무게를 입력하시오. : ");
	scanf_s("%d", &bagWeight);
	struct product P[1000] = { 0, };
	printf("광물의 갯수를 입력하시오. : ");
	int count = 0;
	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) { // 사용자에게 광물 입력받기
		printf("%d번 광물 무게와 광물의 가격을 작성하시오. : ", i+1);
		scanf_s("%lf%lf", &P[i].weight, &P[i].cost);		
		P[i].value = P[i].cost / P[i].weight;
	}

	printFunction(P, count);
	printf("\n\n");

	for (int i = 0; i < count; i++)
	{
		printf("%d광물 %lf %lf %lf \n", i, P[i].weight, P[i].cost, P[i].value);
	}

	quickSort(P, 0, count-1); // 정렬
	printFunction(P, count);
	printf("\n\n");

	FractionalKnapsack(&P, count, bagWeight); // 배낭 알고리즘
}