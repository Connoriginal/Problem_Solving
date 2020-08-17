#include <cstdio>

using namespace std;

char str[100];

int main(void) {
	while(scanf("%[^\n]\n",str)==1)
		printf("%s\n",str);
	return 0;
}