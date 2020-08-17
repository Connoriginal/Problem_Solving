#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int a[101];

int main(void){
  scanf("%d %d",&n,&m);

  vector<vector<int> > edge(n+1);

  for(int i = 0 ; i < m ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  bool flag = true;
  for(int i = 1 ; i <= n ; i++){
    memset(a,-1,sizeof(a));

    queue<int> que;
    que.push(i);
    a[i] = 0;
    while(!que.empty()){
      int cur = que.front();
      que.pop();
      for(int j = 0 ; j < edge[cur].size() ; j++){
        int next = edge[cur][j];
        if(a[next] == -1 || a[cur] + 1 < a[next]){
          a[next] = a[cur] + 1;
          que.push(next);
        }
      }
    }

    for(int j = 1 ; j <= n ; j++){
      if(a[j] > 6 || a[j] == -1){
        flag = false;
        break;
      }
    }

    if(!flag){
      printf("Big World!\n");
      return 0;
    }
  }
  printf("Small World!\n");
  return 0;
}
