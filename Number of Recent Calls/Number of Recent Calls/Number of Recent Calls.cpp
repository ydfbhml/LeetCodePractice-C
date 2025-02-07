#include <stdlib.h>
#include <stdio.h>


#define MAX 3010

typedef struct {
	int *queue;
	int front;
	int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
	RecentCounter* q;

	q = (RecentCounter*)malloc(sizeof(RecentCounter));

	q->queue = (int *)malloc(MAX * sizeof(int));

	q->front = q->rear = 0;

	return q;
}

int recentCounterPing(RecentCounter* obj, int t) {
	//add t
	if ((obj->rear + 1) % MAX == obj->front)
		return -1;

	obj->queue[obj->rear] = t;
	obj->rear = (obj->rear + 1) % MAX;

	//if(t - obj.queue[obj.front] > 3000), remove first element in the queue
	while (t - obj->queue[obj->front] > 3000) {
		obj->front = (obj->front + 1) % MAX;
	}

	//get the length of queue
	int length = (obj->rear - obj->front + MAX) % MAX;
	return length;
}

void recentCounterFree(RecentCounter* obj) {
	free(obj->queue);
}

int main() {
	int t[4] = { 1, 100, 3001, 3002 };
	int i = 0;
	int l = 4;
	int param_1;

	RecentCounter* obj = recentCounterCreate();

	for (i = 0; i < l; i++) {
		param_1 = recentCounterPing(obj, t[i]);
		printf("%d\n", param_1);
	}

	return 0;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/