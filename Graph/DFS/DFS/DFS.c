#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX_NUM 100

typedef struct {
	int vertexNum;
	int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
} Graph;

int visited[MAX_VERTEX_NUM];
#define MAX_QUEUE_SIZE 20 // ť�� �ִ� ũ��
typedef int element; // ť ������ �ڷ����� int�� ����

typedef struct { // ť ����ü
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}
int is_full(QueueType* q) {
	return (q->front ==
		(q->rear + 1) % MAX_QUEUE_SIZE);
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void BFS_Mat(Graph* g, int s) {
	QueueType q;
	init_queue(&q);
	for (int i = 1; i <= g->vertexNum; i++) // visited �迭 �ʱ�ȭ
		visited[i] = 0; // 0: �湮���� ����, 1: �湮����
	visited[s] = 1;
	printf("%d ", s);
	enqueue(&q, s);
	while (!is_empty(&q)) {
		int u = dequeue(&q);
		for (int v = 1; v <= g->vertexNum; v++) {
			if (g->adjMatrix[u][v] == 1 && visited[v] == 0) {
				visited[v] = 1;
				printf("%d ", v);
				enqueue(&q, v);
			}
		}
	}
}
int main() {
	Graph* g = NewGraph(8);
	AddEdge(g, 1, 2);
	AddEdge(g, 1, 3);
	AddEdge(g, 2, 4);
	AddEdge(g, 2, 5);
	AddEdge(g, 3, 5);
	AddEdge(g, 3, 7);
	AddEdge(g, 3, 8);
	AddEdge(g, 4, 5);
	AddEdge(g, 5, 6);
	AddEdge(g, 7, 8);
	printGraph(g);
	printf
	(
		"
		\nDFS: ");
		DFS_Mat(g);
}
