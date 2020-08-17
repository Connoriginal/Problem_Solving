#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		char str[1001];
		scanf("%s",str);
		printf("%c%c\n",str[0],str[strlen(str)-1]);
	}
	return 0;
}