#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct RecommandInfo
{
    char name[100];                  
    struct RecommandInfo *recommender;
};

// 이 위로 수정 금지
void set_recommender(struct RecommandInfo* r, int* cnt, char* n1, char* n2){
    
}
// 이 아래로 수정 금지

int main()
{
    int N;
    scanf("%d", &N);

    char name1[100] = {0};
    char name2[100] = {0};

    struct RecommandInfo friends[100] = {0};
    int friend_count = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", name1, name2);

        set_recommender(friends, &friend_count, name1, name2);
    }

    for (int i = 0; i < friend_count; i++)
    {
        if (friends[i].recommender != NULL)
            printf("%s's recommender: %s\n", friends[i].name, friends[i].recommender->name);
        else
            printf("%s's recommender: NULL\n", friends[i].name);
    }

    return 0;
}
