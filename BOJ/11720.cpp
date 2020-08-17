#include <cstdio>

int t;
int ans = 0, temp;

int main(void) {
	scanf("%d",&t);
	
	while(t--){
		scanf("%1d",&temp);
		ans += temp;
	}
	printf("%d\n",ans);
	return 0;
}