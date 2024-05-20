#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *data){
    pid_t pid;
    pthread_t tid;

    char* thread_name = (char*) data;
    pid = getpid(); // ID of process
    tid = pthread_self(); // pthread 식별

    int i = 0;
    while(i < 3){
        // pthread name, id, iterator, loop
        printf("[%s] pid : %u, tid : %x --- %d\n",thread_name,(unsigned int)pid,(unsigned int)tid,i);
        i++;
        sleep(1);
    }
    pthread_exit(0);
}

int main(){
    pthread_t p_thread[2];
    int thr_id;
    int status;
    char p1[] = "thread_1";
    char p2[] = "thread_2";
    char pp[] = "thread_Main";

    sleep(1);

    // create 1st thread
    thr_id = pthread_create(&p_thread[0],NULL,thread_func,(void *)p1);
    if(thr_id < 0) perror("Fail to create Thread1!\n");

    // create 2nd thread
    thr_id = pthread_create(&p_thread[1],NULL,thread_func,(void *)p2);
    if(thr_id < 0) perror("Fail to create Thread2!\n");

    thread_func((void *)pp);

    // waiting pthread end
    pthread_join(p_thread[0],(void **)&status);
    pthread_join(p_thread[1],(void **)&status);

    return 0;
}