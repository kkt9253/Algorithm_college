#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    double weight; // ����
    double value;  // ��ġ
    double ratio;  // ���� ���� �� ��ġ
} Item;

int compare(const void* a, const void* b) {
    return ((Item*)b)->ratio > ((Item*)a)->ratio ? 1 : -1;
}

void fractionalKnapsack(int n, Item items[], double capacity, double* totalValue) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(Item), compare);

    Item knapsack[1000];
    double totalWeight = 0;
    *totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            knapsack[i] = items[i];
            totalWeight += items[i].weight;
            *totalValue += items[i].value;
        }
        else {
            double remainingWeight = capacity - totalWeight;
            knapsack[i].weight = remainingWeight;
            knapsack[i].value = items[i].ratio * remainingWeight;
            *totalValue += knapsack[i].value;
            break;
        }
    }

    printf("\n�賶�� ���� ���� ����Ʈ:\n");
    for (int i = 0; i < n; i++) {
        if (knapsack[i].weight > 0) {
            printf("���� %d ����: %.2lf, ��ġ: %.2lf\n", i + 1, knapsack[i].weight, knapsack[i].value);
        }
    }
}

int main() {
    int n;
    double capacity, totalValue;

    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &n);

    printf("�賶�� �뷮�� �Է��ϼ���: ");
    scanf("%lf", &capacity);

    Item items[1000];

    for (int i = 0; i < n; i++) {
        printf("���� %d�� ���Կ� ��ġ�� �Է��ϼ���: ", i + 1);
        scanf("%lf %lf", &items[i].weight, &items[i].value);
    }

    fractionalKnapsack(n, items, capacity, &totalValue);

    printf("\n�賶�� ���� ������ �� ��ġ: %.2lf\n", totalValue);

    return 0;
}