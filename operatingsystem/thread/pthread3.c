#include <stdio.h>
#include <pthread.h>

void* ThreadFunc(void *arg){
    printf("%d\n",*(int *)arg + 10);
    return NULL;
}

int main(){
    pthread_t ThreadID;

    long argument = 3;
    pthread_create(&ThreadID,0,&ThreadFunc,(void *)&argument);
    pthread_join(ThreadID,NULL);
    return 0;
}