#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *snow(void *data){
    printf("Let it snow... %s\n",(char *)data);
    pthread_exit(0);
    return NULL;
}

int main(){
    pthread_t mythread;
    const char* data = "Let it snow";
    int result;

    result = pthread_create(&mythread,NULL,(void *(*)(void *))snow,(void *)data);
    if(result){
        exit(1);
    }
    pthread_exit(0);
}