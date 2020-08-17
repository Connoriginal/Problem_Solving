#include <iostream>
#include <cstdio> //scanf, printf
#include <algorithm>
#include <cstring> // strlen() 
#include <stack>

int T;
long long int N, A , B ; //%llu


int main(void){
	scanf("%d",&T);
	
	for(int i = 1 ; i < T + 1 ; i++){
		scanf("%lld",&N);
		A = 0;B = 0;
		long long int temp = N;
		int pt = 1;
		
		while(temp > 0){
			if(temp % 10 == 4) A += pt;
			temp /= 10;
			pt *= 10;
		}
		B = N - A;
		printf("Case #%d: %llu %llu\n",i,A,B);
	}
	
	return 0;
}