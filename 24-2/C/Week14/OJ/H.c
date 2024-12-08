#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Scores
{
    unsigned int korean;
    unsigned int english;
    unsigned int math;
};

// 이 위로 수정 금지
void find_pizza_classes(struct Scores c[], int n){
    int a[5] = {0};
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        sum += (c[i].korean + c[i].english + c[i].math);
        if(sum >= 230){
            a[i] = 1;
            cnt++;
        }
    }
    if(cnt == 0){
        printf("save teacher's wallet");
        return;
    }
    for(int i=0;i<5;i++){
        if(a[i] == 1){
            printf("%d ", i + 1);
        }
    }
}
// 이 아래로 수정 금지

int main()
{
    struct Scores classes[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%u %u %u", &classes[i].korean, &classes[i].english, &classes[i].math);
    }

    find_pizza_classes(classes, 5);

    return 0;
}
