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

bool arr[1001]; // false가 소수
int N,K;
int erase = 0;

int main(void){
	scanf("%d %d",&N,&K);
	int ans = 0;
	
	for(int i = 2 ; i <= N ; i++){
		if(arr[i] == false){
			erase++;
			arr[i] = true;
			if(erase == K)
				ans = i;
			
		}
		for(int j = i * i ; j <= N ; j += i){
			if(arr[j] == false){
				erase++;
				arr[j] = true;
				if(erase == K)
					ans = j;
			}
		}
		if(ans > 0) break;
	}
	
	printf("%d\n",ans);
	return 0;
}

