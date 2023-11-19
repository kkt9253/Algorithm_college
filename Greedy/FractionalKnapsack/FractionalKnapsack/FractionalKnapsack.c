#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    double weight; // 무게
    double value;  // 가치
    double ratio;  // 단위 무게 당 가치
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

    printf("\n배낭에 담은 물건 리스트:\n");
    for (int i = 0; i < n; i++) {
        if (knapsack[i].weight > 0) {
            printf("물건 %d 무게: %.2lf, 가치: %.2lf\n", i + 1, knapsack[i].weight, knapsack[i].value);
        }
    }
}

int main() {
    int n;
    double capacity, totalValue;

    printf("물건의 개수를 입력하세요: ");
    scanf("%d", &n);

    printf("배낭의 용량을 입력하세요: ");
    scanf("%lf", &capacity);

    Item items[1000];

    for (int i = 0; i < n; i++) {
        printf("물건 %d의 무게와 가치를 입력하세요: ", i + 1);
        scanf("%lf %lf", &items[i].weight, &items[i].value);
    }

    fractionalKnapsack(n, items, capacity, &totalValue);

    printf("\n배낭에 담은 물건의 총 가치: %.2lf\n", totalValue);

    return 0;
}