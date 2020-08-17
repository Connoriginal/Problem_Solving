#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int map[501][501];
bool area[501][501];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int wid, ver;

int dfs(int x, int y){
	area[x][y] = true;
	int ret = 1;
	for(int k = 0 ; k < 4 ; k++){
		int nx = x + dx[k]; int ny = y + dy[k];
		if(0 <= nx && nx < ver && 0 <= ny && ny < wid){
			if(map[nx][ny] == 1 && area[nx][ny] == false){
				ret += dfs(nx,ny);
			}
		}
	}
	return ret;
}
int main(void){
	queue<pair<int,int>> que;
	scanf("%d %d",&ver,&wid);
	for(int i = 0 ; i < ver ; i++){
		for(int j = 0 ; j < wid ; j++){
			scanf("%d",&map[i][j]);
			if(map[i][j] == 1){
				que.push(make_pair(i,j));
			}
		}
	}
	
	int len = 0;
	int ans = 0;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if(area[x][y] == false){
			++len;
			ans = max(ans,dfs(x,y));
			
		}
	}

	printf("%d\n%d\n",len,ans);
	return 0;
}