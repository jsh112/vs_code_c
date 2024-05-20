#include <stdio.h>
#include <windows.h>

HANDLE hMutex;
int g_var;

DWORD WINAPI MyThread_0(LPVOID arg){
    for(;;){
        g_var = 0;
        printf("Thread 0 : g_var = %d\n",g_var);
    }
}

DWORD WINAPI MyThread_1(LPVOID arg){
    for(;;){
        g_var = 1;
        printf("Thread 1 : g_var = %d\n",g_var);
    }
}

int main(int argc,char* arv[]){
    HANDLE hThread[2];
    DWORD Threadid[2];

    hThread[0] = CreateThread(NULL, 0, MyThread_0, NULL, 0, &Threadid[0]);
    hThread[1] = CreateThread(NULL, 0, MyThread_1, NULL, 0, &Threadid[1]);

    WaitForMultipleObjects(2,hThread,TRUE,INFINITE);
    return 0;
}