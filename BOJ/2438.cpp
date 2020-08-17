#include <cstdio>

int t;

int main(void){
	scanf("%d",&t);
	
	for(int i = 1 ; i < t+1 ; i++){
		for(int j = 0 ; j < i ; j++)
			printf("*");
		putchar('\n');
	}
	return 0;
}