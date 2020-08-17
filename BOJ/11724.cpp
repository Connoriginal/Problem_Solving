#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool check[1001];
vector<int> edge[1001];

void dfs(int x){
  check[x] = true;
  for(int i = 0 ; i < edge[x].size() ; i++){
    int y = edge[x][i];
    if(!check[y]) dfs(y);
  }
}

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < m ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);edge[v].push_back(u);
  }

  int ans = 0;
  for(int i = 1 ; i <= n ; i++){
    if(!check[i]){
      dfs(i);
      ans++;
    }
  }

  printf("%d\n",ans);
  return 0;
}
