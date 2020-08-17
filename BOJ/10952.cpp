#include <cstdio>

using namespace std;

int a, b;
int main(void) {
	while(scanf("%d %d",&a,&b) == 2 && a && b)
		printf("%d\n",a+b);
	return 0;
}