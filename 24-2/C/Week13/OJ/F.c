#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void sort_str(char* data, unsigned int N){
    for(int i=1;i<N-1;i++){
        int j = i-1;
        
        while(j >= 0 &&)
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    unsigned int N;
    char data[100][100] = {0};
    scanf("%u", &N);
    for (size_t i = 0; i < N; i++)
        scanf("%s", data[i]);

    sort_str(data, N);

    for (size_t i = 0; i < N; i++)
        printf("%s\n", data[i]);

    return 0;
}
j