#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool dcheck[1001];
bool bcheck[1001];
vector<int> vec[1001];

void dfs(int x){
  dcheck[x] = true;
  printf("%d ",x);
  for(int i = 0 ; i < vec[x].size() ; i++){
    int y = vec[x][i];
    if(!dcheck[y]){
      dfs(y);
    }
  }
}

int main(void){
  int n,m,v;
  scanf("%d %d %d",&n,&m,&v);

  for(int i = 0 ; i < m ; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    vec[a].push_back(b);vec[b].push_back(a);
  }

  for(int i = 0 ; i <= n ; i++) sort(vec[i].begin(),vec[i].end());

  dfs(v);
  printf("\n");

  queue<int> q;

  q.push(v);
  bcheck[v] = true;
  while(!q.empty()){
    int next = q.front(); q.pop();
    printf("%d ",next);
    for(int i = 0 ; i < vec[next].size() ; i++){
      int y = vec[next][i];
      if(!bcheck[y]){
        bcheck[y] = true;
        q.push(y);
      }
    }
  }
  printf("\n");
  return 0;
}
