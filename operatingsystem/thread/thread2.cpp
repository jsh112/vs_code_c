#include <conio.h>
#include <iostream>
#include <windows.h>
DWORD WINAPI ThreadFunc(LPVOID Param);

typedef struct stThreadParam
{
    int id;
    int sleeptime;
} ThreadParam;

int main()
{
    HANDLE hThread[4];
    DWORD ThreadID[4];
    ThreadParam tp[4];

    for (int i = 0; i < 4; i++)
    {
        tp[i].id = i;
        tp[i].sleeptime = i * 20;
        hThread[i] = CreateThread(NULL, 0, ThreadFunc, &tp[i], 0, &ThreadID[i]);
    }
    WaitForMultipleObjects(4, hThread, TRUE, INFINITE);
    getch();
    return 0;
}
DWORD WINAPI ThreadFunc(LPVOID Param)
{
    ThreadParam *tp = (ThreadParam *)Param;

    for (int i = 0; i < 10; i++)
    {
        std::cout << std::endl;
        std::cout << "Thread " << tp->id << " : " << i << std::endl;
        Sleep(tp->sleeptime);
    }
    return 0;
}