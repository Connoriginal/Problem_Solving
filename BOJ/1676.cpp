#include <cstdio> 


int N;
int ans = 0;

int main(void){
	scanf("%d",&N);
	for(int i = 5 ; i <= N ; i*=5){
		ans += N/i;
	}
	printf("%d\n",ans);
	return 0;
}