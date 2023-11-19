#include <stdio.h>

void swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

//���
void printArray(int data[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}

void min_heapify(int data[], int size, int i) {

    int j = 2 * i + 1; // ��������� �θ�
    if (j < size - 1 && data[j] > data[j + 1]) // ������� left, right ��
        j++;
    if (j < size && data[i] > data[j]) // ��������� �θ�� �񱳵� ������带 ���ؼ� �θ��� ��������
        swap(data, i, j);
    if (j < size / 2) // ������ ���������� ��� ��������.
        min_heapify(data, size, j);
}

void min_heapsort(int data[], int size) {
    for (int i = size / 2; i >= 0; i--) { // i�� �۾������� ������带 ������.
        min_heapify(data, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(data, i, 0); // ��Ʈ��带 ���ܽ�Ŵ. ����ؼ� ��Ʈ��带 ���ܽ�Ŵ���ν� �迭�� �Ųٷ� ������ ��.
        min_heapify(data, i, 0); // ��Ʈ��带 ���ܽ��ױ⿡ ������ �������⿡ ��������.
    }

}

void max_heapify(int data[], int size, int i) {

    int j = 2 * i + 1; // ��������� �θ�
    if (j < size - 1 && data[j] < data[j + 1]) // ������� left, right ũ��� �� ����
        j++;
    if (j < size && data[i] < data[j]) // �������� �θ��� ũ�� ��
        swap(data, i, j);
    if (j < size / 2) // ������ �̷�������� �� �Ʒ��� ���鵵 ��������. (������ ������ �� �ʿ� X, ���ʿ��� ����)
        max_heapify(data, size, j);
}

void max_heapsort(int data[], int size) {
    for (int i = size / 2; i >= 0; i--) {
        max_heapify(data, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(data, i, 0);
        max_heapify(data, i, 0);
    }
}

int main(void)
{
    int min_data[] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
    int n = sizeof(min_data) / sizeof(min_data[0]);
    min_heapsort(min_data, n);
    printArray(min_data, n);

    printf("\n\n");

    int max_data[] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
    max_heapsort(max_data, n);
    printArray(max_data, n);

    return 0;
}