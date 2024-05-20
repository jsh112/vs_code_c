#include <stdio.h>

int main(){
	int a,b;

    // 472 385 입력
	scanf("%d\n%d",&a,&b);
	// 3,4,5 저장
	int c[3];
	c[2] = a * (b / 100);
	c[1] = a * ((b % 100) / 10);
	c[0] = a * (b % 10);
	
	for(int i=0;i<3;i++){
		printf("%d\n",c[i]);
	}
	
	printf("%d", c[0] + 10 * c[1] + 100 * c[2]);
	return 0;
}