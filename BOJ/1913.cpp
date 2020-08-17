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

int map[1000][1000];
int N,inp;

void solve(int x, int y , int n){
	if(n==1){
		map[x][y] = 1;
		return;
	}
	int tmp = n*n;
	
	for(int i = x ; i < x + n ; i++)
		map[i][y] = tmp--;
	
	for(int i = y+1 ; i < y + n ; i++)
		map[x+n-1][i] = tmp--;
	
	for(int i = x+n-2 ; i >= x ; i--)
		map[i][y+n-1] = tmp--;
	
	for(int i = y +n-2 ; i > y ; i--)
		map[x][i] = tmp--;
	return;
}
int main(void){
	scanf("%d %d",&N,&inp);
	
	int x = 0 , y = 0;
	for(int i = N ; i >= 1 ; i-=2)
		solve(x++,y++,i);
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ",map[i][j]);
			if(map[i][j] == inp){
				x = i+1; y = j+1;
			}
		}
		printf("\n");
	}
	printf("%d %d\n",x,y);
	return 0;
}

