#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Circular_Queue {
    int* mem;
    int end;
    int front;
} C_Queue;
int cq_size(C_Queue* q) {
    return ((q->end) - (q->start)) + 1;
}

int cq_empty(C_Queue* q) {
    return (size(q) == 0) ? 1 : 0;
}

int cq_front(C_Queue* q) {
    if (empty(q)) return -1;
    return *(q->mem + (q->start));
}

int cq_back(C_Queue* q) {
    if (empty(q)) return -1;
    return *((q->mem) + (q->end));
}

int cq_pop(C_Queue* q) {
    //if empty queue
    if (size(q) == 0) {
        return -1;
    }
    return *(q->mem + (q->start)++);

}
void cq_push(C_Queue* q, int in) {
    (q->end)++;
    *(q->mem + (q->end)) = in;
}
void cq_init(C_Queue* q, int max) {
    q->mem = (int*)malloc(sizeof(int) * max);
    q->end = -1;
    q->front = -1;

}

int main(int argc, const char* argv[]) {
    //1 2 3 4 5 6 7 8 9 10
    //2번
    //2 3 4 5 6 7 8 9 10 1
    //1번
    //3 4 5 6 7 8 9 10 1
    //3번 3번 3번
    //9 10 1 3 4 5 6 7 8
    //1번
    //10 1 3 4 5 6 7 8
    //3번 3번 3번 3번
    //5 6 7 8 10 1 3 4
    return 0;
}
