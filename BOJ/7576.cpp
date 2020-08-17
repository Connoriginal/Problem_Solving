#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int map[1001][1001];
int graph[1001][1001];

int n,m;

int main(void){
  scanf("%d %d",&n,&m);

  queue<pair<int,int> > que;

  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      int temp;
      scanf("%d",&temp);
      map[i][j] = temp;
      if(temp == -1){
        graph[i][j] = -1;
      }
      if(temp == 1) {
        que.push(make_pair(i,j));
        graph[i][j] = 1;
      }
    }
  }

  while(!que.empty()){
    int x = que.front().first, y = que.front().second;
    que.pop();
    for(int k = 0 ; k < 4 ; k++){
      int nx = x + dx[k], ny = y + dy[k];
      if(0 <= nx && nx < m && 0 <= ny && ny < n){
        if(map[nx][ny] == 0){
          if(graph[nx][ny] == 0 || graph[nx][ny] > graph[x][y] + 1){
            graph[nx][ny] = graph[x][y] + 1;
            que.push(make_pair(nx,ny));
          }
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      if(graph[i][j] == 0){
        printf("-1\n");
        return 0;
      }
      ans = max(ans,graph[i][j]);
    }
  }

  printf("%d\n",ans-1);
  return 0;
}
