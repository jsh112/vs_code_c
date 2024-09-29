#include <stdio.h>
#include <stdlib.h>

// 2차원 배열의 주소를 출력하는 함수
void printArrayAddresses(int **pa, int rows, int cols)
{
    printf("2차원 배열의 주소:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("pa[%d]: %p\n", i, (void *)pa[i]); // 각 행의 시작 주소
        for (int j = 0; j < cols; j++)
        {
            printf("pa[%d][%d]: %d\n", i, j, (char *)&pa[i][j] - (char *)&pa[0][0]);            // 각 요소의 주소
            printf("*(pa + %d) + %d: %d\n", i, j, (char *)(*(pa + i) + j) - (char *)&pa[0][0]); // 포인터 산술
        }
    }
}

int main()
{
    int rows = 3;
    int cols = 25;

    // 1. 포인터 포인터 선언
    int **pa;

    // 2. 행 크기만큼 메모리 할당
    pa = (int **)malloc(rows * sizeof(int *));
    if (pa == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 3. 각 행에 대해 열 크기만큼 메모리 할당
    for (int i = 0; i < rows; i++)
    {
        pa[i] = (int *)malloc(cols * sizeof(int));
        if (pa[i] == NULL)
        {
            printf("메모리 할당 실패\n");
            return 1;
        }
    }

    // 4. 배열에 값 대입
    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            pa[i][j] = value++;
        }
    }

    // 5. 주소 출력 함수 호출
    printArrayAddresses(pa, rows, cols);

    // 6. 메모리 해제
    for (int i = 0; i < rows; i++)
    {
        free(pa[i]); // 각 행에 대해 할당된 메모리 해제
    }
    free(pa); // 행 포인터 배열에 대해 할당된 메모리 해제

    return 0;
}
