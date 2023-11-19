#include <stdio.h>

void swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

//출력
void printArray(int data[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}

void min_heapify(int data[], int size, int i) {

    int j = 2 * i + 1; // 하위노드의 부모
    if (j < size - 1 && data[j] > data[j + 1]) // 하위노드 left, right 비교
        j++;
    if (j < size && data[i] > data[j]) // 하위노드의 부모와 비교된 하위노드를 비교해서 부모의 정렬해줌
        swap(data, i, j);
    if (j < size / 2) // 나머지 하위힙들을 모두 재정렬함.
        min_heapify(data, size, j);
}

void min_heapsort(int data[], int size) {
    for (int i = size / 2; i >= 0; i--) { // i가 작아질수록 상위노드를 정렬함.
        min_heapify(data, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(data, i, 0); // 루트노드를 제외시킴. 계속해서 루트노드를 제외시킴으로써 배열에 거꾸로 정렬이 됨.
        min_heapify(data, i, 0); // 루트노드를 제외시켰기에 정렬이 무너졌기에 재정렬함.
    }

}

void max_heapify(int data[], int size, int i) {

    int j = 2 * i + 1; // 하위노드의 부모
    if (j < size - 1 && data[j] < data[j + 1]) // 하위노드 left, right 크기비교 후 선택
        j++;
    if (j < size && data[i] < data[j]) // 하위노드와 부모노드 크기 비교
        swap(data, i, j);
    if (j < size / 2) // 정렬이 이루어졌을때 그 아래의 노드들도 재정렬함. (조건의 상위는 할 필요 X, 불필요한 연산)
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