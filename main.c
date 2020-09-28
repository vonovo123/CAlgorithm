#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//n : 잘린 정사각형의 크기
//*start 시작점
//**array 전체 정사각형
//*result 결과를 담은 배열
void conqure(int n, int xStart, int yStart, int** array, int* result) {
    //시작점의 타일색
    int sColor =   *(*(array + yStart) + xStart);
    //모든색이 같은지 판별 플래그
    int isSameColor = 0;
    //1개일때는 무조건 리턴
    if (n == 1) {
        *(result + sColor) += 1;
        return;
    }
    for (int i = yStart; i < yStart + n; i++) {
        for (int j = xStart; j < xStart + n; j++) {
            if (sColor != *(*(array + i) + j)) {
                isSameColor = 1;
                break;
            }
        }
        if (isSameColor == 1) break;
    }
    if (isSameColor == 0) {
        *(result + sColor) += 1;
    }
    else {
        int nSize = n / 2;
        conqure(nSize, xStart, yStart, array, result);
        conqure(nSize, xStart + nSize, yStart, array, result);
        conqure(nSize, xStart, yStart + nSize, array, result);
        conqure(nSize, xStart + nSize, yStart + nSize, array, result);
    }
}
//n : 정사각형의 가로세로 길이
void solve2630() {
    int n = 0;
    scanf("%d", &n);
    //정사각형 초기화
    int** array = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        *(array + i) = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", *(array + i) + j);
        }
    }
    int* result = (int*)malloc(sizeof(int) * 2);
    *(result + 0) = 0;
    *(result + 1) = 0;
    conqure(n, 0, 0, array, result);
    printf("%d\n", *(result + 0));
    printf("%d\n", *(result + 1));

}
int main(int argc, const char* argv[]) {
    solve2630();
}
