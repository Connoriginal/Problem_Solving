#include <cstdio> 
#include <algorithm>
#include <queue>

using namespace std;
int map[51][51];
bool check[51][51];
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,1,-1,-1};
int w, h;

void bfs(int x, int y){
	queue<pair<int,int>> que;
	que.push(make_pair(x,y));
	check[x][y] = true;
	while(!que.empty()){
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for(int k = 0 ; k < 8 ; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0 <= nx && nx < h && 0 <= ny && ny < w){
				if(map[nx][ny] == 1 && check[nx][ny] == false){
					que.push(make_pair(nx,ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}
int main(void){
	while(true){
		scanf("%d %d",&w,&h);
		if(w == 0 && h == 0)
			break;
		
		for(int i = 0 ; i < h ; i++){
			for(int j = 0 ; j < w ; j++){
				scanf("%d",&map[i][j]);
				check[i][j] = false;
			}
		}
		
		int cnt = 0;
		for(int i = 0 ; i < h ; i++){
			for(int j = 0 ; j < w ; j++){
				if(map[i][j] == 1 && check[i][j] == false){
					bfs(i,j);
					cnt++;
				}
			}
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}