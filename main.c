#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
int main(int argc, const char* argv[]) {
    int t = 0;
    //turn
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        //n : 프린트 입력 수, m : 궁금한 프린트 순서
        int n = 0, m = 0;
        scanf("%d %d", &n, &m);
        Queue* q = malloc(sizeof(Queue));
        init(q, Max);
        for (int i = 0; i < n; i++) {
            int in = 0;
            int max = 0;
            scanf("%d", &in);
            if (in > max) max = in;
            push(q, in);
        }
        printf("%d\n", solve1966(q, m));
    }
}
