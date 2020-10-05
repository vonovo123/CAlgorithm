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
    //�����ؾ��ϴ� ����
    int index = m;
    //���(������� ��µǴ���)
    int result = 0;
    //�ִ� �߿䵵
    int max = findMaxValue(q);
    //Ž�� index
    //index�� ��µɶ� ����
    while (size(q) != 0) {
        //�Ǿ���¿�û�� �߿䵵�� �ִ��϶�
        if (front(q) == max) {
            //�Ǿ���¿�û�� ��ġ�� �����ؾ��ϴ� index�� ������
            if (q->start == index) {
                //�������  + 1
                result++;
                //Ž������
                break;
                //�Ǿ���¿�û�� ��ġ�� �����ؾ��ϴ� index�� �ٸ���
            }
            else {
                //�̾Ƴ���
                pop(q);
                //������� + 1;
                result++;
                //�ٽ� �ִ밪�� ã�´�.
                max = findMaxValue(q);

            }
            //�Ǿ���¿�û�� �߿䵵�� �ִ밡 �ƴϸ�
        }
        else {
            //�Ǿ���¿�û�� ��ġ�� �����ؾ��ϴ� index�� ������
            if (q->start == index) {
                //�ǵڷ� �������ϱ⶧���� �����ؾ��ϴ� index�� ��ġ�� ť�� �Ǹ������� �ȴ�.
                index = q->end + 1;
            }
            int p = pop(q);
            //queue�� �� �ڷ� ������.
            push(q, p);

        }
    }
    return result;
}