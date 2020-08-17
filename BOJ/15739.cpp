#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool check[10001];
int list[101][101];

int main(void){
	int N;
	scanf("%d",&N);
	
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			int tmp;
			scanf("%d",&tmp);
			list[i][j] = tmp;
			check[tmp] = true;
		}
	}
	
	bool ans = true;
	for(int i = 1 ; i <= N*N ; i++){
		if(check[i] == false){
			ans = false;
			break;
		}
	}
	if(ans == false){
		printf("FALSE\n");
		return 0;
	}
	
	int sum = N*(N*N + 1)/2;
	
	int a = 0 , b = 0;
	for(int i = 0 ; i < N ; i++){
		a += list[i][i]; b += list[N-i-1][N-i-1];
		int w = 0, h = 0;
		for(int j = 0 ; j < N ; j++){
			w +=list[i][j];
			h +=list[j][i];
		}
		if(w != sum || h != sum){
			ans = false;
			break;
		}
	}
	
	if(a != sum || b != sum){
		ans = false;
	}
	
	if(ans == false){
		printf("FALSE\n");
	}
	else{
		printf("TRUE\n");
	}
	
	return 0;
}

