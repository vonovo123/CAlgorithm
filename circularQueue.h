#pragma once
#define MAX 50
typedef struct Circular_Queue {
    int* mem;
    //ť�� ��������
    int front;
    //ť�� ������
    int back;

} C_Queue;

//ũ��
int cq_size(C_Queue* q);
//��ť����
int cq_empty(C_Queue* q);
//�Ǿտ�� Ȯ��
int cq_front(C_Queue* q);
//�ǵڿ�� Ȯ��
int cq_back(C_Queue* q);
//������ �ֱ�
void cq_front_push(C_Queue* q, int in);
//������ ����
int cq_front_pop(C_Queue* q);
//�ڷ� �ֱ�
void cq_back_push(C_Queue* q, int in);
//�ڷ� ����
int cq_back_pop(C_Queue* q);
//ť�� ��ü��� ���
void cq_print(C_Queue* q);
//ť�� ��ü��Ҹ� �������� �� ������ �̵�
void to_left(C_Queue* q);
//ť�� ��ü��Ҹ� ���������� �� ������ �̵�
void to_right(C_Queue* q);
//�ʱ�ȭ
void cq_init(C_Queue* q, int max);

int solve1021(C_Queue* cq, int n, int pc, int* array);