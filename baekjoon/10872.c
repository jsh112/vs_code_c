#include <stdio.h>

int main(){

    int a;
    scanf("%d",&a);

    int sum = 1;
    for(int i=1;i<=a;i++){
        sum = sum * i;
    }
    printf("%d\n",sum);

    return 0;
}