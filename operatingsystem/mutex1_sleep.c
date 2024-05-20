#include <stdio.h>
#include <windows.h>

HANDLE hMutex;
int g_var;

DWORD WINAPI MyThread_1(LPVOID arg);
DWORD WINAPI MyThread_2(LPVOID arg);

int main(int argc,char *argv[]){
    HANDLE hThread[2];
    DWORD Threadid[2];

    hMutex = CreateMutex(NULL,FALSE,NULL);

    hThread[0] = CreateThread(NULL,0,MyThread_1,NULL,0,&Threadid[0]);
    hThread[1] = CreateThread(NULL,0,MyThread_2,NULL,0,&Threadid[1]);

    WaitForMultipleObjects(2,hThread,TRUE,INFINITE);

    CloseHandle(hMutex);
    return 0;
}

DWORD WINAPI MyThread_1(LPVOID arg){
    for(;;){
        WaitForSingleObject(hMutex,INFINITE);
        g_var = 1;
        Sleep(1);
        printf("Thread 1 : g_var = %d\n",g_var);
        ReleaseMutex(hMutex);
    }
    return 0;
}

DWORD WINAPI MyThread_2(LPVOID arg){
    for(;;){
        WaitForSingleObject(hMutex,INFINITE);
        g_var = 2;
        Sleep(1);
        printf("Thread 2 : g_var = %d\n",g_var);
        ReleaseMutex(hMutex);
    }
    return 0;
}