#pragma once
#define MAX 50
typedef struct Circular_Queue {
    int* mem;
    //큐의 시작지점
    int front;
    //큐의 끝지점
    int back;

} C_Queue;

//크기
int cq_size(C_Queue* q);
//빈큐여부
int cq_empty(C_Queue* q);
//맨앞요소 확인
int cq_front(C_Queue* q);
//맨뒤요소 확인
int cq_back(C_Queue* q);
//앞으로 넣기
void cq_front_push(C_Queue* q, int in);
//앞으로 빼기
int cq_front_pop(C_Queue* q);
//뒤로 넣기
void cq_back_push(C_Queue* q, int in);
//뒤로 빼기
int cq_back_pop(C_Queue* q);
//큐의 전체요소 출력
void cq_print(C_Queue* q);
//큐의 전체요소를 왼쪽으로 한 포인터 이동
void to_left(C_Queue* q);
//큐의 전체요소를 오른쪽으로 한 포인터 이동
void to_right(C_Queue* q);
//초기화
void cq_init(C_Queue* q, int max);

int solve1021(C_Queue* cq, int n, int pc, int* array);