#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "circularQueue.h"
int main(int argc, const char* argv[]) {
    C_Queue* cq = malloc(sizeof(C_Queue));
    cq_init(cq, MAX);
    int n = 0;
    int p_c = 0;
    int result = 0;
    scanf("%d %d",&n, &p_c);

    int* in_array = malloc(sizeof(int) * p_c);
    for (int i = 0; i < p_c; i ++) {
        scanf("%d", in_array + i);
    }

    printf("%d\n", solve1021(cq, n, p_c, in_array));
}
