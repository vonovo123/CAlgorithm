#pragma once
#define MIN(a,b)((a) < (b) ? (a) : (b))
#define Max 2000000

typedef struct _Queue {
    int* mem;
    int end;
    int start;
} Queue;
int size(Queue* q);
int empty(Queue* q);
int front(Queue* q);
int back(Queue* q);
int pop(Queue* q);
void push(Queue* q, int in);
void init(Queue* q, int max);
