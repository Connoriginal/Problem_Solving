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

int cost[1001][3];
int d[1001][3];

int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < 3 ; j++){
			scanf("%d",&cost[i][j]);
		}
	}
	
	d[0][0] = cost[0][0]; d[0][1] = cost[0][1]; d[0][2] = cost[0][2];
	
	for(int i = 1 ; i < N ; i++){
		d[i][0] = cost[i][0] + min(d[i-1][1],d[i-1][2]);
		d[i][1] = cost[i][1] + min(d[i-1][0],d[i-1][2]);
		d[i][2] = cost[i][2] + min(d[i-1][0],d[i-1][1]);
	}
	
	printf("%d\n",min(d[N-1][0],min(d[N-1][1],d[N-1][2])));
	return 0;
}

