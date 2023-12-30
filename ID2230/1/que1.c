#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int front, rear, size;
} Deque;

void initDeque(Deque* deq) {
    deq->front = -1;
    deq->rear = 0;
    deq->size = 0;
}

int isEmpty(Deque* deq) {
    return deq->size == 0;
}

int isFull(Deque* deq) {
    return deq->size == MAX_SIZE;
}

void add_First(Deque* deq, int x) {
    if (isFull(deq)) {
        printf("Deque is full.\n");
        return;
    }
    if (deq->front == -1)
        deq->front = 0;
    else if (deq->front == 0)
        deq->front = MAX_SIZE - 1;
    else
        deq->front--;
    deq->array[deq->front] = x;
    deq->size++;
}

void add_Last(Deque* deq, int x) {
    if (isFull(deq)) {
        printf("Deque is full.\n");
        return;
    }
    if (deq->front == -1)
        deq->front = 0;
    deq->rear = (deq->rear + 1) % MAX_SIZE;
    deq->array[deq->rear] = x;
    deq->size++;
}

int remove_First(Deque* deq) {
    if (isEmpty(deq)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int removed = deq->array[deq->front];
    if (deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = 0;
    } else {
        deq->front = (deq->front + 1) % MAX_SIZE;
    }
    deq->size--;
    return removed;
}

int remove_Last(Deque* deq) {
    if (isEmpty(deq)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int removed = deq->array[deq->rear];
    if (deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = 0;
    } else if (deq->rear == 0) {
        deq->rear = MAX_SIZE - 1;
    } else {
        deq->rear--;
    }
    deq->size--;
    return removed;
}

int main() {
    Deque deq;
    initDeque(&deq);
    
    add_Last(&deq, 1);
    add_First(&deq, 2);
    add_Last(&deq, 3);
    add_First(&deq, 4);
    remove_Last(&deq);
    remove_First(&deq);
   // printf("Removed from last: %d\n", remove_Last(&deq));
   // printf("Removed from first: %d\n", remove_First(&deq));
   // printf("Removed from last: %d\n", remove_Last(&deq));
   // printf("Removed fro m first: %d\n", remove_First(&deq));
    

    return 0;
}
