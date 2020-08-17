#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[51][51];
int check[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int M, N, K;

void dfs(int x, int y, int cnt){
	check[x][y] = cnt;
	for(int k = 0 ; k < 4 ; k++){
		int nx = x + dx[k]; int ny = y + dy[k];
		if(map[nx][ny] == 1 && check[nx][ny] == 0){
			dfs(nx,ny,cnt);
		}
	}
}

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&M,&N,&K);
		
		for(int i = 0 ; i < K ; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			map[v][u] = 1;
		}
		
		int cnt = 0;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				if(map[i][j] == 1 && check[i][j] == 0)
					dfs(i,j,++cnt);
			}
		}
		
		printf("%d\n",cnt);
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				map[i][j] = 0;
				check[i][j] = 0;
			}
		}
	}
	return 0;
}