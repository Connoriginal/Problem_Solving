#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool prime[1000000];//false가 소수

int main(void){
	int n;
	prime[1] = true;
	while(true){
		scanf("%d",&n);
		int cnt = 0;
		
		if(n == 0)
			break;
		for(int i = 2 ; i*i <= 2*n ; i++){
			if(prime[i] == false){
				for(int j = i * i ; j <= 2*n ; j += i){
					prime[j] = true;
				}
			}
		}
		
		for(int i = n+1 ; i <= 2*n ; i++){
			if(prime[i] == false)
				cnt++;
		}
		printf("%d\n",cnt);
		
	}


	return 0;
}