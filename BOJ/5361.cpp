#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const float A = 350.34, B = 230.90, C = 190.55, D = 125.30, E = 180.90;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		float ans = a*A + b*B + c*C + d*D + e*E;
		printf("$%.2f\n",ans);
	}
	return 0;
}

