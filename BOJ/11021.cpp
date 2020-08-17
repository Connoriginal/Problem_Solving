#include <cstdio>

using namespace std;
int t;
int a, b;
int main(void) {
	scanf("%d",&t);
	for(int i = 1 ; i < t+1; i++){
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",i,a+b);
	}
	return 0;
}