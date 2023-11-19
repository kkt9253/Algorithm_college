#include <stdio.h>
#define MAX 10

void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[MAX];//�ӽ� �迭
    while (i <= q && j <= r) {
        if (data[i] <= data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }//������ ���������� ����. �� �� �ٸ� ���ʿ��� ���� ������ �̹� ���ĵ����Ƿ� �״�� �־��ָ� ��.
    while (i <= q)
        tmp[k++] = data[i++];
    while (j <= r)
        tmp[k++] = data[j++];
    for (int i = p; i <= r; i++) {
        data[i] = tmp[i];
    }//�պ��� ���� ���� �迭�� �־���
}

void mergeSort(int data[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(data, p, q);//���ݺ� ���� 5 2 1 0
        mergeSort(data, q + 1, r);//�Ĺݺ� ���� 1 5 8 9 10
        merge(data, p, q, r);//�պ�
    }
}

void printArray(int data[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}

int main() {

    int data[MAX] = { 3,31,48,73,8,11,20,29,65,15 };
    int n = sizeof(data) / sizeof(data[0]);

    mergeSort(data, 0, n - 1);
    printArray(data, n);
    return 0;
}