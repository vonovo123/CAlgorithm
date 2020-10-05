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

void printQueue(Queue* q) {
    for (int i = 0; i < size(q); i++) {
        printf("%d ", *(q->mem + i));
    }
    printf("\n");
}

int findMaxValue(Queue* q) {
    int max = 0;
    for (int i = q->start; i <= q->end; i++) {
        if (*(q->mem + i) > max) {
            max = *(q->mem + i);
        }
    }
    return max;
}

int solve1966(Queue* q, int m) {
    //추적해야하는 순서
    int index = m;
    //결과(몇번만에 출력되는지)
    int result = 0;
    //최대 중요도
    int max = findMaxValue(q);
    //탐색 index
    //index가 출력될때 까지
    while (size(q) != 0) {
        //맨앞출력요청의 중요도가 최대일때
        if (front(q) == max) {
            //맨앞출력요청의 위치가 추적해야하는 index와 같을때
            if (q->start == index) {
                //결과값에  + 1
                result++;
                //탐색종료
                break;
                //맨앞출력요청의 위치가 추적해야하는 index와 다르면
            }
            else {
                //뽑아내고
                pop(q);
                //결과값에 + 1;
                result++;
                //다시 최대값을 찾는다.
                max = findMaxValue(q);

            }
            //맨앞출력요청의 중요도가 최대가 아니면
        }
        else {
            //맨앞출력요청의 위치가 추적해야하는 index와 같을때
            if (q->start == index) {
                //맨뒤로 보내야하기때문에 추적해야하는 index의 위치는 큐의 맨마지막이 된다.
                index = q->end + 1;
            }
            int p = pop(q);
            //queue의 맨 뒤로 보낸다.
            push(q, p);

        }
    }
    return result;
}