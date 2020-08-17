#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

int M,N;
bool prime[1000001];

int main(void){
	scanf("%d %d",&M,&N);
	for(int i = 2 ; i <= N ; i++){
		if(prime[i] == false){
			if(i>=M)
				printf("%d\n",i);
			for(int j = i * 2 ; j <= N ; j += i)
				prime[j] = true;
		}
	}
	return 0;
}

