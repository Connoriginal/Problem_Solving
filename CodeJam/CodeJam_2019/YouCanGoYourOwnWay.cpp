#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>  


int T, N;

int main(void){
	scanf("%d",&T);
	for(int i = 1 ; i < T + 1 ; i++){
		char ans[1000000];
		char lydia[1000000];
		scanf("%d %s",&N,lydia);
		for(int j = 0 ; j < 2*N-2; j++){
			ans[j] = (lydia[j] == 'E') ? 'S' : 'E';
		}
		ans[2*N-2] = '\0';
		printf("Case #%d: %s\n",i,ans);
	}
	
	return 0;
}