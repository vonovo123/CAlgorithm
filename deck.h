#pragma once
typedef struct _Deck {
    int* mem;
    int front;
    int back;
}Deck;
#define MIN(a,b)((a) < (b) ? (a) : (b))
#define Max 100000

//Deck�� ũ��
int d_size(Deck* d);
//�� ����
int d_empty(Deck* d);
//deck�� ��������Ҹ� ����
int d_back(Deck* d);
//���������� ������ ���� ����� ��ġ�� ���� ���� ����
int d_front(Deck* d);
//Deck�� ������ ������
int pop_front(Deck* d);
//Deck�� �ڷ� ������
int pop_back(Deck* d);
//Deck�� �ڷ� �ֱ�
void push_back(Deck* d, int in);
//Deck�� ������ �ֱ�
void push_front(Deck* d, int in);
//Deck ��� ���
void d_print(Deck* d, int isR);
//Deck�ʱ�ȭ
void d_init(Deck* d, int max);
void solve5430();