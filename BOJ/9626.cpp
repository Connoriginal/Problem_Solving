#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char str[11][11];

int main(void){
	int M,N;
	scanf("%d %d",&M,&N);

	
	int u,l,r,d;
	scanf("%d %d %d %d",&u,&l,&r,&d);
	
	for(int i = 0 ; i < M ; i++){
		scanf("%s",str[i]);
	}
	
	for(int i = 0 ; i < u + M + d ; i++){
		for(int j = 0 ; j < l + N + r ; j++){
			if(u <= i && i < u + M && j == l){
				printf("%s",str[i-u]);
				j += N-1;
			}
			else{
				char tmp = ((i+j) % 2 == 0) ? '#':'.';
				printf("%c",tmp);
			}
		}
		printf("\n");
	}
	return 0;
}

