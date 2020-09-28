#include "queue.h"
int size(Queue* q) {
    return ((q->end) - (q->start)) + 1;
}

int empty(Queue* q) {
    return (size(q) == 0) ? 1 : 0;
}

int front(Queue* q) {
    if (empty(q)) return -1;
    return *(q->mem + (q->start));
}

int back(Queue* q) {
    if (empty(q)) return -1;
    return *((q->mem) + (q->end));
}

int pop(Queue* q) {
    //if empty queue
    if (size(q) == 0) {
        return -1;
    }
    return *(q->mem + (q->start)++);

}
void push(Queue* q, int in) {
    (q->end)++;
    *(q->mem + (q->end)) = in;
}
void init(Queue* q, int max) {
    q->mem = (int*)malloc(sizeof(int) * max);
    q->end = -1;
    q->start = 0;

}
