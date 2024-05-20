#include <pthread.h>
#include <stdio.h>

int thread_args[3] = {0,1,2};

void *Thread(void *arg){
    int i;
    
    for(i=0;i<5;i++){
        printf("thread %d : %dth iteration\n",*(int *)arg,i);
    }
    pthread_exit(0);
    return NULL;
}

int main(){
    int i;
    pthread_t threads[3];

    for(i=0;i<3;i++){
        printf("Thread Num %d Create!!\n",i);
        pthread_create(&threads[i],NULL,(void *(*)(void *))Thread,&thread_args[i]);
    }
    pthread_exit(0);
}