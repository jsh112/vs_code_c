#include <stdio.h>

struct customer_t {
    char name[100];
    unsigned int num_of_visits;
};

int my_strcmp(const char* s1, const char* s2) {
    while (*s1) {
        if (*s1 != *s2) {
            return 1;
        }
        s1++;
        s2++;
    }
    return 0;
}

void my_strcpy(char* s1, char* s2) {
    while (*s2) {
        *s1 = *s2;
        s1++;
        s2++;
    }
}
struct customer_t arr[100] = {{0}, 0};

int main() {
    int n;
    scanf("%d", &n);
    char _name[100] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", &arr[i].name);
        my_strcpy(_name, arr[i].name);
        for (int j = 0; j < i; j++) {
            if (!my_strcmp(arr[j].name, _name)) {
                arr[j].num_of_visits++;
            }
        }
    }

    int max = 0, idx;
    for (int i = 0; i < n; i++) {
        if (max < arr[i].num_of_visits) {
            max = arr[i].num_of_visits;
            idx = i;
        }
    }
    printf("%s", arr[idx].name);

    return 0;
}