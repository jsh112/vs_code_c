#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int x = 1;

void *func(void *data){
    x++;
    pthread_exit((void *)23);
}

int main(){
    pthread_t mythread;
    int result;
    int i;

    result = pthread_create(&mythread,NULL,(void *(*)(void *))func,NULL);
    if(result) exit(1);
    pthread_join(mythread,(void **)&i);
    printf("%d\n",i);
}