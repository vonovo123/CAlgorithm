#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circularQueue.h"


//ũ��
int cq_size(C_Queue* q) {
    return (q->back) - (q->front) + 1;
}
//��ť����
int cq_empty(C_Queue* q) {
    return (cq_size(q) == 0) ? 1 : 0;
}

//�Ǿտ�� Ȯ��
int cq_front(C_Queue* q) {
    if (cq_empty(q) == 1) return -1;
    return *(q->mem + (q->front));
}
//�ǵڿ�� Ȯ��
int cq_back(C_Queue* q) {
    if (cq_empty(q)) return -1;
    return *((q->mem) + (q->back + 1));
}
//������ �ֱ�
void cq_front_push(C_Queue* q, int in) {
    if (cq_size(q) == MAX) {
        printf("%s", "circular_queue overflow");
        return;
    }
    if (q->front == 0) {
        for (int i = q->back; i >= 0; i--) {
            *(q->mem + (i + 1)) = *(q->mem + i);
        }
        *(q->mem) = in;
        (q->back)++;
    }
    else {
        //�Ǿտ�� �ϳ� ������ ������ �̵�
        q->front--;
        //�� �����Ϳ� �� �Ҵ�
        *(q->mem + (q->front)) = in;
    }
}
//������ ����
int cq_front_pop(C_Queue* q) {
    //if empty queue
    if (cq_size(q) == 0) {
        return -1;
    }
    return *(q->mem + (q->front)++);

}
//�ڷ� �ֱ�
void cq_back_push(C_Queue* q, int in) {
    (q->back)++;
    *(q->mem + (q->back)) = in;
}
//�ڷ� ����
int cq_back_pop(C_Queue* q) {

    return *(q->mem + (q->back)--);
}
//ť�� ��ü��� ���
void cq_print(C_Queue* q) {
    if (cq_size(q) == 0) {
        printf("empty C_queue");
        return;
    }
    for (int i = q->front; i <= q->back; i++) {
        printf("%d ", *(q->mem + i));
    }
    printf("\n");
}

//ť�� ��ü��Ҹ� �������� �� ������ �̵�
void to_left(C_Queue* q) {
    int pop = cq_front_pop(q);
    cq_back_push(q, pop);
}
//ť�� ��ü��Ҹ� ���������� �� ������ �̵�
void to_right(C_Queue* q) {
    int pop = cq_back_pop(q);
    cq_front_push(q, pop);
}
//�ʱ�ȭ
void cq_init(C_Queue* q, int max) {
    q->mem = (int*)malloc(sizeof(int) * max);
    q->front = 0;
    q->back = -1;
}

int solve1021(C_Queue* cq, int n, int pc, int* array ) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        cq_back_push(cq, i);
    }

    //pop �� ����
    int c_pop = 0;
    while (c_pop != pc) {
        //��ȯť�� ù��° ��Ұ� �̾ƾ��� ��ҿ� ������
        if (cq_front(cq) == *(array + c_pop)) {
            int pop = cq_front_pop(cq);
            c_pop++;
        }
        else {
            int d_p = cq_size(cq) / 2;
            int t_p = 0;
            //�̾ƾ��ϴ� ����� ���� �ε��� ã��
            for (int i = cq->front; i <= cq->back; i++) {
                if (*(cq->mem + i) == *(array + c_pop)) {
                    break;
                }
                t_p++;
            }
            if (d_p >= t_p) {
                result += t_p;
                for (int i = 0; i < t_p; i++) {
                    to_left(cq);
                }
            }
            else {
                result += cq_size(cq) - t_p;
                for (int i = 0; i < cq_size(cq) - t_p; i++) {
                    to_right(cq);
                }
            }
        }
    }

    return result;
}