#include <stdio.h>

int main() {
    char str[110];
    gets(str);

    char name[100] = {0}, num[100] = {0}, addr[100] = {0};

    int i = 0, cnt = 0;
    while (str[i] && str[i + 3] != '-') {
        name[i] = str[i];
        i++;
        cnt++;
    }
    name[i] = '\0';
    printf("Name: %s\n", name);

    int cnt2 = cnt;
    while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
        num[i - cnt] = str[i];
        i++;
        cnt2++;
    }
    num[i - cnt] = '\0';
    printf("Phonenumber: %s\n", num);

    while (str[i]) {
        addr[i - cnt2] = str[i];
        i++;
    }
    addr[i - cnt2] = '\0';
    printf("Address: %s\n", addr);

    return 0;
}