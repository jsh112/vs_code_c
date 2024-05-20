#include <stdio.h>
#include <pthread.h>

void *ThreadRoutine(void* arg){
    printf("%s\n",(char *)arg);
    return NULL;
}

int main(){
    pthread_t threadID;

    char argument[10] = "Hello";
    pthread_create(&threadID,NULL,&ThreadRoutine,(void*) argument);

    pthread_join(threadID,(void**)NULL);
    return 0;
}