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
int d_pop_front(Deck* d) {
    //Deck이 비어있으면 -1을 리턴
    if (d_empty(d) == 1) {
        return -1;
    }
    //마지막으로 앞으로빼낸 요소의 포인터의 다음 포인터의 값을 담는다.
    int re = *(d->mem + (++(d->front)));

    return re;
}
//Deck의 뒤로 빼내기
int d_pop_back(Deck* d) {
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
void d_push_back(Deck* d, int in) {
    //deck의 마지막요소의 위치 + 1이 최대크기와 같으면 FULL
    if ((d->back) + 1 == Max) {
        printf("Deck overflow");
        return;
    }
    //마지막요소의 위치포인터를 뒤로 하나 밀고 요소를 넣어준다.
    *((d->mem) + ++(d->back)) = in;
}
//Deck의 앞으로 넣기
void d_push_front(Deck* d, int in) {
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

void d_print(Deck* d, int isR) {
    printf("[");
    if (isR == 0) {//정방향
        for (int i = d->front + 1; i <= d->back; i++) {
            if (i < d->back) printf("%d,", *(d->mem + i));
            else printf("%d", *(d->mem + i));
        }
    }
    else {//역방향
        for (int i = d->back; i >= d->front + 1; i--) {
            if (i > d->front + 1) printf("%d,", *(d->mem + i));
            else printf("%d", *(d->mem + i));
        }
    }

    printf("]\n");
}

void solve5430() {
    //테스트케이스의수
    int t = 0;
    scanf("%d", &t);
    //테스트케이스만큼 반복진행
    for (int i = 0; i < t; i++) {
        //Deck 할당
        Deck* d = malloc(sizeof(Deck));
        //Deck 초기화
        d_init(d, Max);
        //사용할 문자열 메모리 할당
        char* p = malloc(sizeof(char) * 100000 + 1);
        //문자열 0으로 초기화
        for (int i = 0; i < 100000; i++) {
            *(p + i) = 0;
        }
        //커맨드 문자열 scan
        scanf("%s", p);

        //입력받을 숫자의 개수
        int n = 0;
        scanf("%d\n", &n);
        char s;
        char dot;
        //덱요소
        int num;
        scanf("%c", &s); // [
        for (int i = 0; i < n; i++) {
            // i , or i]
            scanf("%d%c", &num, &dot);
            d_push_back(d, num);
        }
        //turn
        int i = 0;
        char c;
        int isR = 0;//0 정방향 1 역방향
        int isE = 0;
        while ((c = *(p + i)) == 'D' || (c = *(p + i)) == 'R') {
            if (c == 'R') {//reverse
                isR = !isR;
            }
            else {//delete
                if (d_size(d) == 0) {
                    isE = 1;
                    break;
                }
                if (isR) d_pop_back(d);
                else d_pop_front(d);
            }
            i++;
        }
        if (isE) printf("error\n");
        else d_print(d, isR);


        free(p);
        free(d);
    }

}

void d_init(Deck* d, int max) {
    d->mem = (int*)malloc(sizeof(int) * max);
    d->front = -1;
    d->back = -1;
}
