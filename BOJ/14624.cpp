#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	if(n%2 == 0){
		printf("%s\n","I LOVE CBNU");
		return 0;
	}
	
	for(int i = 0 ; i < n ; i++)
		printf("*");
	printf("\n");
	for(int i = 0 ; i < (n+1)/2 ; i++){
		for(int j = n/2 - i; j > 0 ; j--){
			printf(" ");
		}
		printf("*");
		if(i > 0){
			for(int j = 0 ; j < 2 * i -1 ; j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	return 0;
}