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
    //1개탐색(마지막)이면 해당타일의 색에 + 1 한 후 탐색 종료
    if (n == 1) {
        *(result + sColor) += 1;
        return;
    }
    //y시작점 부터 n 개
    for (int i = yStart; i < yStart + n; i++) {
        //x시작점 부터 n개 탐색하면서 모두 같은색 타일인지 확인
        for (int j = xStart; j < xStart + n; j++) {
            //하나라도 색이 다르면
            if (sColor != *(*(array + i) + j)) {
                //판별 플레그를 1로 바꾸고
                isSameColor = 1;
                //탐색 종료
                break;
            }
        }
        //판별 플레그가 1이면 더이상 탐색하지 않고 종료
        if (isSameColor == 1) break;
    }
    //탐색한 타일이 모두 같은 색이면
    if (isSameColor == 0) {
        //해당 타일색에 +1 하고 탐색 종료
        *(result + sColor) += 1;
    }
    //영역의 타일색이 하나라도 다르면
    else {
        //해당영역 분할탐색
        int nSize = n / 2;
        //일사분면에서 n/2 만큼
        conqure(nSize, xStart, yStart, array, result);
        //이사분면에서 n/2 만큼
        conqure(nSize, xStart + nSize, yStart, array, result);
        //삼사분면에서 n/2만큼
        conqure(nSize, xStart, yStart + nSize, array, result);
        //사사분면에서 n/2만큼
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
