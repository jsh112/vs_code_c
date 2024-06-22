#include <stdio.h>

int main(){

    int n,x;
    scanf("%d %d",&n, &x);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
        if(x > array[i]){
            printf("%d ",array[i]);
        }
    }

    return 0;
}