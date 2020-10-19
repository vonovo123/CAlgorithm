#pragma once
typedef struct _Deck {
    int* mem;
    int front;
    int back;
}Deck;
#define MIN(a,b)((a) < (b) ? (a) : (b))
#define Max 100000

//Deck의 크기
int d_size(Deck* d);
//빈덱 여부
int d_empty(Deck* d);
//deck의 마지막요소를 리턴
int d_back(Deck* d);
//마지막으로 앞으로 빠진 요소의 위치의 다음 값을 리턴
int d_front(Deck* d);
//Deck의 앞으로 빼내기
int pop_front(Deck* d);
//Deck의 뒤로 빼내기
int pop_back(Deck* d);
//Deck의 뒤로 넣기
void push_back(Deck* d, int in);
//Deck의 앞으로 넣기
void push_front(Deck* d, int in);
//Deck 요소 출력
void d_print(Deck* d, int isR);
//Deck초기화
void d_init(Deck* d, int max);
void solve5430();