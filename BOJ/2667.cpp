#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int map[26][26];
int graph[26][26];

int n;
vector<int> ans;

int dfs(int x, int y, int cnt){
  int ans = 1;
  graph[x][y] = cnt;
  for(int k = 0 ; k < 4 ; k++){
    int nx = x + dx[k], ny = y + dy[k];
    if(0 <= nx && nx < n && 0 <= ny && ny < n){
      if(map[nx][ny] == 1 && graph[nx][ny] == 0){
        ans += dfs(nx,ny,cnt);
      }
    }
  }
  return ans;
}

int main(void){
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%1d",&map[i][j]);
    }
  }

  int cnt = 1;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(map[i][j] == 1 && graph[i][j] == 0){
        ans.push_back(dfs(i,j,cnt));
        cnt++;
      }
    }
  }

  sort(ans.begin(),ans.end());

  printf("%d\n",cnt-1);
  for(int i = 0 ; i < ans.size() ; i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}




/* bfs 사용
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[26][26];
int graph[26][26];
int N;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans[25*25];

void bfs(int x, int y , int cnt){
	queue<pair<int,int>> que;
	que.push(make_pair(x,y));
	graph[x][y] = cnt;
	while(!que.empty()){
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for(int k = 0 ; k < 4 ; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0 <= nx && nx < N && 0 <= ny && ny < N){
				if(map[nx][ny] == 1 && graph[nx][ny] == 0){
					que.push(make_pair(nx,ny));
					graph[nx][ny] = cnt;
				}
			}
		}
	}
}

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%1d",&map[i][j]);
		}
	}

	int cnt = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(map[i][j] == 1 && graph[i][j] == 0){
				bfs(i,j,++cnt);
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			ans[graph[i][j]]+=1;
		}
	}

	sort(ans+1,ans+1+cnt);

	printf("%d\n",cnt);

	for(int i = 1 ; i <= cnt ; i++)
		printf("%d\n",ans[i]);

	return 0;
}
*/
