#include <stdio.h>

int main() {
    char str[101];
    scanf("%[^\n]", str);

    char name[100];

    int i = 0;
    // 이름 저장
    while (str[i] && !(str[i] >= '0' && str[i] <= '9')) {
        name[i] = str[i];
        i++;
    }
    name[i] = 0;

    char number[100];
    int j = 0;
    while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
        number[j++] = str[i++];
    
    number[j] = 0;

    int k = 0;
    char addr[100];
    while (str[i])
        addr[k++] = str[i++];
    addr[k] = 0;

    printf("Name: %s\n", name);
    printf("Phonenumber: %s\n", number);
    printf("Address: %s\n", addr);

    return 0;
}