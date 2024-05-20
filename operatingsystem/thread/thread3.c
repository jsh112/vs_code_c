#include <stdio.h>
#include <windows.h>

DWORD WINAPI Thread1(PVOID pArg);
DWORD WINAPI Thread2(PVOID pArg);

DWORD WINAPI Thread1(PVOID pArg)
{
    int i = 1;
    while (i++ < 20)
    {
        printf("A ");
        printf("B ");
        printf("C ");
    }
    return 0;
}

DWORD WINAPI Thread2(PVOID pArg)
{
    int i = 1;
    while (i++ < 20)
    {
        printf("1 ");
        printf("2 ");
        printf("3 ");
    }
    return 0;
}

int main()
{
    HANDLE hThread1, hThread2;
    DWORD dwThread1 = 0, dwThread2 = 1;
    int i = 1;

    hThread1 = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThread1);
    hThread2 = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThread2);
    CloseHandle(hThread1);
    CloseHandle(hThread2);
    while (i++ < 50)
    {
        printf("m ");
        printf("m ");
        printf("m ");
    }

    return 0;
}