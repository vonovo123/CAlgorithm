#include "divideNconquer.h"
//n : 잘린 정사각형의 크기
//*start 시작점
//**array 전체 정사각형
//*result 결과를 담은 배열
void conqure(int n, int xStart, int yStart, int** array, int* result) {
    //시작점의 타일색
    int sColor = *(*(array + yStart) + xStart);
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
/// <summary>
/// 이차원 분할정복
/// </summary>
/// <param name="n">분할후 한변의 길이</param>
/// <param name="xStart">x좌표</param>
/// <param name="yStart">y좌표</param>
/// <param name="array">이차원 배열</param>
void conqure1992(int n, int xStart, int yStart, int** array) {
    //시작점의 숫자
    int s = *(*(array + yStart) + xStart);
    //모든색이 같은지 판별
    int isSameNum = 0;
    //모든색이 같으면 0 하나라도 다르면 1
    for (int i = yStart; i < yStart + n; i++) {
        for (int j = xStart; j < xStart + n; j++) {
            if (s != *(*(array + i) + j)) {
                isSameNum = 1;
                break;
            }
        }
        if (isSameNum == 1) break;
    }
    //모두 같은 색이면 해당하는 수(0:검정 1 흰)을 출력하고 리턴
    if (isSameNum == 0) {
        printf("%d", s);
        return;
    }
    //하나라도 다른색이 있으면
    else {
        //분할한 화면이 2*2일때
        if (n == 2) {
            printf("(");
            //n이 2일때는 2*2 분면의 숫자 차례로 출력하고 리턴
            for (int i = yStart; i < yStart + n; i++) {
                for (int j = xStart; j < xStart + n; j++) {
                    printf("%d", *(*(array + i) + j));
                }
            }
            printf(")");
            //printf("\n");
            return;
        }
        //2*2 이상일때
        else {
            int nSize = n / 2;
            printf("(");
            conqure1992(nSize, xStart, yStart, array);
            conqure1992(nSize, xStart + nSize, yStart, array);
            conqure1992(nSize, xStart, yStart + nSize, array);
            conqure1992(nSize, xStart + nSize, yStart + nSize, array);
            printf(")");
        }
    }
}

//n : 잘린 정사각형의 크기
//*start 시작점
//**array 전체 정사각형
//*result 결과를 담은 배열
void conqure1780(int n, int xStart, int yStart, int** array, int* result) {
    //시작점의 숫자
    int s = *(*(array + yStart) + xStart);
    //모든색이 같은지 판별 플래그
    int isSameNum = 0;
    for (int i = yStart; i < yStart + n; i++) {
        for (int j = xStart; j < xStart + n; j++) {
            if (s != *(*(array + i) + j)) {
                isSameNum = 1;
                break;
            }
        }
        if (isSameNum == 1) break;
    }
    if (isSameNum == 0) {
        *(result + (s + 1)) += 1;
        return;
    }
    else {
        int nSize = n / 3;
        conqure1780(nSize, xStart, yStart, array, result);
        conqure1780(nSize, xStart + nSize, yStart, array, result);
        conqure1780(nSize, xStart + nSize + nSize, yStart, array, result);

        conqure1780(nSize, xStart, yStart + nSize, array, result);
        conqure1780(nSize, xStart + nSize, yStart + nSize, array, result);
        conqure1780(nSize, xStart + nSize + nSize, yStart + nSize, array, result);

        conqure1780(nSize, xStart, yStart + nSize + nSize, array, result);
        conqure1780(nSize, xStart + nSize, yStart + nSize + nSize, array, result);
        conqure1780(nSize, xStart + nSize + nSize, yStart + nSize + nSize, array, result);
    }
}

long long int conquer1629(int a, int b, int c) {
    //기저 b가 1일때(a 자신일때) c로 나눈 나머지 리턴
    if (b == 1) return a % c;
    //우선 b를 절반으로 나누어 결과값 도출
    long long int result = conquer1629(a, b / 2, c);
    //a를 b/2번 곱한값을 c 로 나눈 결과값을 제곱하여 다시 c로 나누면 a를 b번 곱해 c로 나눈 결과값과 같다.
    result = (result * result) % c;
    //단 b가 홀수일 경우, 한번더 a를 곱하고 그 값을 c로 나눈 값과 같다.
    if (b % 2) {
        result = (result * a) % c;
    }
    return result;
}


//n : 정사각형의 가로세로 길이
void solve2630(){
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

void solve1992(int n, int** array) {
    conqure1992(n, 0, 0, array);
}

void solve1780(int n, int** array) {
    int* result = malloc(sizeof(int) * 3);
    *(result) = 0; //0 -1
    *(result + 1) = 0; //1 0
    *(result + 2) = 0;//2 1
    conqure1780(n, 0, 0, array, result);
    for (int i = 0; i <= 2; i++) {
        printf("%d\n", *(result + i));
    }
}
long long int solve1629(long long int a, long long int b, long long int c) {
    long long int result = conquer1629(a, b, c);
    return result;
}
