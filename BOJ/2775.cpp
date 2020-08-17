#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int liv[15][15];

int main(void){
	int t;
	scanf("%d",&t);
	for(int i = 1 ; i < 15 ; i++){
		liv[0][i] = i;
	}
	
	while(t--){
		int k , n;
		scanf("%d %d",&k,&n);
		for(int i = 1 ; i <= k ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(liv[i][j] == 0){
					for(int w = 1 ; w <= j ; w++){
						liv[i][j] += liv[i-1][w];
					}
				}
			}
		}
		printf("%d\n",liv[k][n]);
	}
	return 0;
}