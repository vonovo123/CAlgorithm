#include "divideNconquer.h"
//n : �߸� ���簢���� ũ��
//*start ������
//**array ��ü ���簢��
//*result ����� ���� �迭
void conqure(int n, int xStart, int yStart, int** array, int* result) {
    //�������� Ÿ�ϻ�
    int sColor = *(*(array + yStart) + xStart);
    //������ ������ �Ǻ� �÷���
    int isSameColor = 0;
    //1��Ž��(������)�̸� �ش�Ÿ���� ���� + 1 �� �� Ž�� ����
    if (n == 1) {
        *(result + sColor) += 1;
        return;
    }
    //y������ ���� n ��
    for (int i = yStart; i < yStart + n; i++) {
        //x������ ���� n�� Ž���ϸ鼭 ��� ������ Ÿ������ Ȯ��
        for (int j = xStart; j < xStart + n; j++) {
            //�ϳ��� ���� �ٸ���
            if (sColor != *(*(array + i) + j)) {
                //�Ǻ� �÷��׸� 1�� �ٲٰ�
                isSameColor = 1;
                //Ž�� ����
                break;
            }
        }
        //�Ǻ� �÷��װ� 1�̸� ���̻� Ž������ �ʰ� ����
        if (isSameColor == 1) break;
    }
    //Ž���� Ÿ���� ��� ���� ���̸�
    if (isSameColor == 0) {
        //�ش� Ÿ�ϻ��� +1 �ϰ� Ž�� ����
        *(result + sColor) += 1;
    }
    //������ Ÿ�ϻ��� �ϳ��� �ٸ���
    else {
        //�ش翵�� ����Ž��
        int nSize = n / 2;
        //�ϻ�и鿡�� n/2 ��ŭ
        conqure(nSize, xStart, yStart, array, result);
        //�̻�и鿡�� n/2 ��ŭ
        conqure(nSize, xStart + nSize, yStart, array, result);
        //���и鿡�� n/2��ŭ
        conqure(nSize, xStart, yStart + nSize, array, result);
        //���и鿡�� n/2��ŭ
        conqure(nSize, xStart + nSize, yStart + nSize, array, result);
    }
}
/// <summary>
/// ������ ��������
/// </summary>
/// <param name="n">������ �Ѻ��� ����</param>
/// <param name="xStart">x��ǥ</param>
/// <param name="yStart">y��ǥ</param>
/// <param name="array">������ �迭</param>
void conqure1992(int n, int xStart, int yStart, int** array) {
    //�������� ����
    int s = *(*(array + yStart) + xStart);
    //������ ������ �Ǻ�
    int isSameNum = 0;
    //������ ������ 0 �ϳ��� �ٸ��� 1
    for (int i = yStart; i < yStart + n; i++) {
        for (int j = xStart; j < xStart + n; j++) {
            if (s != *(*(array + i) + j)) {
                isSameNum = 1;
                break;
            }
        }
        if (isSameNum == 1) break;
    }
    //��� ���� ���̸� �ش��ϴ� ��(0:���� 1 ��)�� ����ϰ� ����
    if (isSameNum == 0) {
        printf("%d", s);
        return;
    }
    //�ϳ��� �ٸ����� ������
    else {
        //������ ȭ���� 2*2�϶�
        if (n == 2) {
            printf("(");
            //n�� 2�϶��� 2*2 �и��� ���� ���ʷ� ����ϰ� ����
            for (int i = yStart; i < yStart + n; i++) {
                for (int j = xStart; j < xStart + n; j++) {
                    printf("%d", *(*(array + i) + j));
                }
            }
            printf(")");
            //printf("\n");
            return;
        }
        //2*2 �̻��϶�
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

//n : �߸� ���簢���� ũ��
//*start ������
//**array ��ü ���簢��
//*result ����� ���� �迭
void conqure1780(int n, int xStart, int yStart, int** array, int* result) {
    //�������� ����
    int s = *(*(array + yStart) + xStart);
    //������ ������ �Ǻ� �÷���
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
    //���� b�� 1�϶�(a �ڽ��϶�) c�� ���� ������ ����
    if (b == 1) return a % c;
    //�켱 b�� �������� ������ ����� ����
    long long int result = conquer1629(a, b / 2, c);
    //a�� b/2�� ���Ѱ��� c �� ���� ������� �����Ͽ� �ٽ� c�� ������ a�� b�� ���� c�� ���� ������� ����.
    result = (result * result) % c;
    //�� b�� Ȧ���� ���, �ѹ��� a�� ���ϰ� �� ���� c�� ���� ���� ����.
    if (b % 2) {
        result = (result * a) % c;
    }
    return result;
}


//n : ���簢���� ���μ��� ����
void solve2630(){
    int n = 0;
    scanf("%d", &n);
    //���簢�� �ʱ�ȭ
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
