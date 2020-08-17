#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int len[101][101];
int land[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N;

void dfs(int x, int y , int cnt){
	land[x][y] = cnt;
	for(int k = 0 ; k < 4 ; k++){
		int nx = x + dx[k]; int ny = y + dy[k];
		if(0 <= nx && nx < N && 0 <= ny < N){
			if(map[nx][ny] == 1 && land[nx][ny] == 0){
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main(void){
	queue<pair<int,int>> que;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&map[i][j]);
			len[i][j] = -1;
			if(map[i][j] == 1){
				que.push(make_pair(i,j));
				len[i][j] = 0;
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(map[i][j] == 1 && land[i][j] == 0){
				dfs(i,j,++cnt);
			}
		}
	}

	while(!que.empty()){
		int x = que.front().first; int y = que.front().second;
		que.pop();
		for(int k = 0 ; k < 4 ; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if(0 <= nx && nx < N && 0 <= ny && ny < N){
				if(len[nx][ny] == -1){
					land[nx][ny] = land[x][y];
					len[nx][ny] = len[x][y] + 1;
					que.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	int ans = -1;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			for(int k = 0 ; k < 4 ; k++){
				int ni = i + dx[k]; int nj = j + dy[k];
				if(0 <= ni && ni < N && 0 <= nj && nj < N){
					if(land[i][j] != land[ni][nj]){
						if(ans == -1 || ans > len[i][j] + len[ni][nj])
							ans = len[i][j] + len[ni][nj];
					}
				}
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}