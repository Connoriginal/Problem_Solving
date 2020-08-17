#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int cost,sum = 0;
	scanf("%d",&cost);
	for(int i = 0 ; i < 9 ; i++){
		int tmp;
		scanf("%d",&tmp);
		sum += tmp;
	}
	printf("%d\n",cost - sum);
	return 0;
}

