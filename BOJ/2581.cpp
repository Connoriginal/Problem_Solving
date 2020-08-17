#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool prime[10001]; // false가 소수
int pmin = 10001;
int ps = 0;
int M,N;

int main(void){
	scanf("%d %d",&M,&N);
	
	for(int i = 2 ; i * i <= N ; i++){
		if(prime[i] == false){
			for(int j = i*i ; j <= N ; j += i){
				prime[j] = true;
			}
		}
	}
	
	prime[1] = true;
	for(int i = M ; i <= N ; i++){
		if(prime[i] == false){
			pmin = min(pmin,i);
			ps += i;
		}
	}
	
	if(ps == 0){
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n",ps,pmin);
	return 0;
}