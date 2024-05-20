#include <stdio.h>
#include <pthread.h>

void *ThreadRoutine(void *arg){
    pthread_t id = pthread_self();

    printf("thread ID (TID) :: %lu\n",id);
    return NULL;
}

int main(){
    pthread_t threadID;

    pthread_create(&threadID,NULL,&ThreadRoutine,NULL);

    pthread_join(threadID,NULL);
}