#include <stdio.h>

int main(){

    int num;
    scanf("%d",&num);
    int array[num];
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    }

    int x;
    int cnt = 0;
    scanf("%d",&x);
    for(int i=0;i<num;i++){
        if(array[i] == x) cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}