#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool prime[10001]; // false가 소수

int main(void){
	int t;
	scanf("%d",&t);
	prime[1] = true;
	while(t--){
		int n;
		scanf("%d",&n);
		
		for(int i = 2 ; i*i <= n ; i++){
			if(prime[i] == false){
				for(int j = i * i ; j <= n ; j+=i){
					prime[j] = true;
				}
			}
		}
		
		int fir,sec;
		for(int i = 2 ; i <= n/2 ; i++){
			if(prime[i] == false && prime[n-i] == false){
				fir = (i < n - i) ? i : n-i;
				sec = n - fir;
			}
		}
		
		printf("%d %d\n",fir,sec);
	}
	return 0;
}

