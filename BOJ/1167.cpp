#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<pair<int,int> > edge[100001];
int dm[100001];

void bfs(int node){
  queue<int> que;
  que.push(node); dm[node] = 0;

  while(!que.empty()){
    int x = que.front(); que.pop();
    for(int i = 0 ; i < edge[x].size() ; i++){
      int y = edge[x][i].first;
      int len = edge[x][i].second;
      if(dm[y] == -1){
        que.push(y);
        dm[y] = dm[x] + len;
      }
    }
  }
}

int main(void){
  int v;
  scanf("%d",&v);

  for(int i = 1 ; i <= v ; i++){
    int from;
    scanf("%d",&from);
    while(true){
      int at, len;
      scanf("%d",&at);
      if(at == -1) break;
      scanf("%d",&len);
      edge[from].push_back(make_pair(at,len));
    }
  }

  memset(dm,-1,sizeof(dm));

  bfs(1);

  int node = 0;
  int m = 0;

  for(int i = 1 ; i <= v ; i++){
    if(dm[i] > m){
      m = dm[i];
      node = i;
    }
  }

  memset(dm,-1,sizeof(dm));

  bfs(node);

  int ans = 0;

  for(int i = 1 ; i <= v ; i++){
    if(dm[i] > ans) ans = dm[i];
  }

  printf("%d\n",ans);
  return 0;
}
