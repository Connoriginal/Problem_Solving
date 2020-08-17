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
	int N,F;
	scanf("%d %d",&N,&F);
	
	int ans = 0;
	N /= 100;
	N *= 100;
	for(int i = 0 ; i < 100 ; i++){
		if(N % F == 0){
			ans += i;
			break;
		}
		N++;
	}
	
	if(ans < 10){
		printf("0%d\n",ans);
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}

