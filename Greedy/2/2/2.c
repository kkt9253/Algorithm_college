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
	double pivot = data[r].value; // �Ǻ��� == ����
	int i = p - 1;   // �Ǻ����� ���� ������ ���� || �̹� ������ �� ������ �ε���
	for (int j = p; j <= r; j++) // �񱳵Ǵ� �ε���
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
		bag_List[i] = i+1; // ���� ���� ����Ʈ�� ����.
		currentBagWeight += p[i].weight; // ���濡 ���� ���� ���
		value_Sum += p[i].cost; // ���濡 ���� ���� �� �ֱ�
		S = p[++i]; // �״��� ������ �ٲ�
	}

	if (bagWeight - currentBagWeight > 0) {
		bag_List[i] = i + 1;
		value_Sum += p[i].value * (bagWeight - currentBagWeight);
	}
	printf("���濡 ��� ��ġ�� ���� %lf / ", value_Sum);
	for (int j = 0; j < count; j++) {
		printf("��� ����Ʈ�� %d ", bag_List[j]);
	}
	printf("�̴�.");

}

int main() {
	int bagWeight = 0;
	printf("������ ���Ը� �Է��Ͻÿ�. : ");
	scanf_s("%d", &bagWeight);
	struct product P[1000] = { 0, };
	printf("������ ������ �Է��Ͻÿ�. : ");
	int count = 0;
	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) { // ����ڿ��� ���� �Է¹ޱ�
		printf("%d�� ���� ���Կ� ������ ������ �ۼ��Ͻÿ�. : ", i+1);
		scanf_s("%lf%lf", &P[i].weight, &P[i].cost);		
		P[i].value = P[i].cost / P[i].weight;
	}

	printFunction(P, count);
	printf("\n\n");

	for (int i = 0; i < count; i++)
	{
		printf("%d���� %lf %lf %lf \n", i, P[i].weight, P[i].cost, P[i].value);
	}

	quickSort(P, 0, count-1); // ����
	printFunction(P, count);
	printf("\n\n");

	FractionalKnapsack(&P, count, bagWeight); // �賶 �˰���
}