#include <stdio.h>

#define p 5 // number of process
#define r 3 // number of resource type

int main()
{
    int available[r] = {10, 5, 7};
    int work[r] = {0};
    int max[p][r] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocate[p][r] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 2, 2}, {0, 0, 2}};
    int need[p][r] = {0};
    int finished[p] = {0};

    for (int j = 0; j < r; j++){
        for (int i = 0; i < p; i++){
            available[j] = available[j] - allocate[i][j];
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }
    for (int i = 0; i < r; i++) work[i] = available[i];
    for (int i = 0; i < p; i++){
        int cnt = 0;
        for (int j = 0; j < r; j++){
            if (finished[i] == 0){
                if (need[i][j] <= work[j]) cnt++;
            }
        }
        if (cnt == r){
            finished[i] = 1;
            for (int j = 0; j < r; j++) work[j] = work[j] + allocate[i][j];
            printf("Process %d\n", i);
            i = -1;
        }
    }
    return 0;
}