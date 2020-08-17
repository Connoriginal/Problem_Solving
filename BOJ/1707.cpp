#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int check[20001];
vector<int> edge[20001];

bool bfs(int x){
  queue<int> que;
  que.push(x);check[x] = 1;

  while(!que.empty()){
    int now = que.front();que.pop();
    for(int i = 0 ; i < edge[now].size() ; i++){
      int next = edge[now][i];
      if(check[next] == 0){
        check[next] = 3 - check[now];
        que.push(next);
      }
      else if(check[next] == check[now]){
        return false;
      }
    }
  }
  return true;
}

int main(void){
  int t;
  scanf("%d",&t);

  while(t--){
    int v,e;
    scanf("%d %d",&v,&e);


    for(int i = 0 ; i < e ; i++){
      int u,v;
      scanf("%d %d",&u,&v);
      edge[u].push_back(v);edge[v].push_back(u);
    }

    bool ans = true;

    for(int i = 1 ; i <= v ; i++){
      if(check[i] == 0){
        if(bfs(i) == false)
          ans = false;
      }
    }

    if(ans)
      printf("YES\n");
    else
      printf("NO\n");

    for(int i = 1 ; i <= v ; i++){
      check[i] = 0; edge[i].clear();
    }
  }
  return 0;
}
