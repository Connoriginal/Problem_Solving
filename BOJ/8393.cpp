#include <cstdio>

int t;
int ans = 0;

int main(void){
	scanf("%d",&t);
	for(int i = 0 ; i <= t ; i++) ans += i;
	printf("%d\n",ans);
	return 0;
}