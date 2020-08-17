#include <cstdio>

int t;
int min = 1000000, max = -1000000;

int main(void){
	scanf("%d",&t);
	while(t--){
		int temp;
		scanf("%d",&temp);
		max = (temp > max)? temp : max;
		min = (temp < min)? temp : min;
	}
	printf("%d %d\n",min,max);
	return 0;
}