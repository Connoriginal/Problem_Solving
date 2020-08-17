#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int num[10];

int main(void){
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i = 1 ; i <= n ; i++){
		int tmp = i;
		while(tmp >= 10){
			num[tmp%10]++;
			tmp /= 10;
		}
		num[tmp]++;
	}
	printf("%d\n",num[d]);
	return 0;
}

