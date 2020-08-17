#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
	int cnt = 1;
	int tmp;
	scanf("%d",&tmp);
	while(scanf(",%d",&tmp) == 1)
		cnt++;
	printf("%d\n",cnt);
	return 0;
}