#include <stdio.h>

int main() {
    char protocol[110] = {0};
    scanf("%[^:]", protocol);
    printf("PROTOCOL: %s\n", protocol);

    for (int i = 0; i < 3; i++) {
        getchar();
    }
    char domain[110] = {0};
    scanf("%[^/]", domain);
    printf("DOMAIN: %s\n", domain);

    getchar();
    char path[110] = {0};
    scanf("%[^?]", path);
    printf("PATH: %s\n", path);

    getchar();
    char param[110] = {0};
    scanf("%[^#]", param);
    printf("PRAMETER: %s\n", param);

    getchar();
    char frag[110] = {0};
    scanf("%[^\n]", frag);
    printf("FRAGMENT: %s\n", frag);

    return 0;
}