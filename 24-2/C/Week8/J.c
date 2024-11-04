#include <stdio.h>

int main(){
    
    char type[10];
    unsigned int A[11];

    scanf("%s arr",type);
    int i=0;
    while(i != 10){
        scanf("[%d]", &A[i]);
        i++;
    }
    
    return 0;
}