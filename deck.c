//
//  main.c
//  c_algorithym
//
//  Created by KWONHYUNWOO on 14/02/2020.
//  Copyright © 2020 KWONHYUNWOO. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "deck.h"

#define MIN(a,b)((a) < (b) ? (a) : (b))
#define Max 10000

//Deck의 크기는
int d_size(Deck* d) {
    //마지막요소의 포인터에서 마지막에 앞으로빼내진 요소의 포인터를 빼준값과 같다.
    return (d->back) - (d->front);
}
//size가 0 이면 1을 리턴
int d_empty(Deck* d) {
    return d_size(d) == 0 ? 1 : 0;
}
//deck의 마지막요소를 리턴
int d_back(Deck* d) {
    return (d_empty(d) == 1) ? -1 : *(d->mem + (d->back));
}
//마지막으로 앞으로 빠진 요소의 위치의 다음 값을 리턴
int d_front(Deck* d) {
    return (d_empty(d) == 1) ? -1 : *(d->mem + ((d->front) + 1));
}
//Deck의 앞으로 빼내기
int pop_front(Deck* d) {
    //Deck이 비어있으면 -1을 리턴
    if (d_empty(d) == 1) {
        return -1;
    }
    //마지막으로 앞으로빼낸 요소의 포인터의 다음 포인터의 값을 담는다.
    int re = *(d->mem + (++(d->front)));

    return re;
}
//Deck의 뒤로 빼내기
int pop_back(Deck* d) {
    //Deck이 비어있으면 -1을 리턴
    if (d_empty(d) == 1) {
        return -1;
    }
    //Deck의 마지막 요소 포인터의 값을 담고 마지막 요소 포인터를 앞으로 당긴다.
    int re = *(d->mem + (d->back)--);
    //마지막요소 포인터 값을 리턴한다.
    return re;
}
//Deck의 뒤로 넣기
void push_back(Deck* d, int in) {
    //deck의 마지막요소의 위치 + 1이 최대크기와 같으면 FULL
    if ((d->back) + 1 == Max) {
        printf("Deck overflow");
        return;
    }
    //마지막요소의 위치포인터를 뒤로 하나 밀고 요소를 넣어준다.
    *((d->mem) + ++(d->back)) = in;
}
//Deck의 앞으로 넣기
void push_front(Deck* d, int in) {
    //맨마지막 요소의 위치 + 1 이 최대크기와 같으면 FULL
    if ((d->back) + 1 == Max) {
        printf("Deck overflow");
        return;
    }
    //앞으로 빼낸적 없는 deck에 요소를 앞으로 넣을때
    if (d->front == -1) {
        //deck의 끝부터 첫요소까지를 한칸씩 뒤로 밀어낸다.
        for (int i = d->back; i >= 0; i--) {
            *((d->mem) + (i + 1)) = *((d->mem) + i);
        }
        //마지막요소의 위치포인터 + 1;
        (d->back)++;
        //deck의 맨 앞에 새로운 요소 삽입
        *((d->mem)) = in;
        //앞으로 빼낸적이 있는 deck에 요소를 앞으로 넣을때
        }
    else 
        {
        //마지막으로 앞으로 빼낸 요소의 포인터에 새로운 요소를 덮어씌운다.
        *((d->mem) + (d->front)) = in;
        //마지막으로 앞으로 빼낸 요소의 포인터위치를 한칸 앞으로 밀어낸다.
        (d->front)--;
    }
};

void d_init(Deck* d, int max) {
    d->mem = (int*)malloc(sizeof(int) * max);
    d->front = -1;
    d->back = -1;
}
