#include <cstdio> 
#include <algorithm>
#include <queue>

using namespace std;
int map[101][101];
int path[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N, M;

void bfs(int x, int y, int cnt){
	queue<pair<int,int>> que;
	que.push(make_pair(x,y));
	path[x][y] = cnt;
	while(!que.empty()){
		x = que.front().first; y = que.front().second;
		que.pop();
		for(int k = 0 ; k < 4 ; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if(0 <= nx && nx < N && 0 <= ny && ny < M){
				if(map[nx][ny] == 1 && path[nx][ny] == 0){
					que.push(make_pair(nx,ny));
					path[nx][ny] = path[x][y] + 1;
				}
			}
		}
	}
}
int main(void){
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	bfs(0,0,1);
	
	printf("%d\n",path[N-1][M-1]);
	return 0;
}