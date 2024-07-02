/*
    문제:
    두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다. 
    수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.
    입력:
    첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.
    출력:
    첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.

    풀이:
    정렬을 하고, num[i] < num[i + 1] 일때마다 cnt++를 해주면 된다. cnt는 1부터 시작
*/

/*
#include <stdio.h>

int main(){

    int num[10], cnt = 1;
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
        num[i] = num[i] % 42;
    }
    
     int i, j, key;

    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for(i=1; i<10; i++){
        key = num[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for(j=i-1; j>=0 && num[j]>=key; j--){
            num[j+1] = num[j]; // 레코드의 오른쪽으로 이동
        }
        num[j+1] = key;
    }

    for(int i=0;i<9;i++){
        if(num[i] < num[i + 1])cnt++;
    }
    printf("%d",cnt);

    return 0;
}
*/

#include <stdio.h>

int main(){

    int a[42] = {0,};
    int num[10], cnt = 0;
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
        num[i] = num[i] % 42;
        a[num[i]]++;
    }

    for(int i=0;i<42;i++){
        if(a[i] != 0) cnt++;
    }
    printf("%d",cnt);

    return 0;
}