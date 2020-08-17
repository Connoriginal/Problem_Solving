#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> cost(n+1,0), ind(n+1,0), ans(n+1,0);
  vector<vector<int> > edge(n+1);

  for(int i = 1 ; i <= n ; i++){
    int tmp, num;
    cin >> tmp >> num;
    cost[i] = tmp;
    ind[i] = num;
    for(int j = 0 ; j < num ; j++){
      int u;
      cin >> u;
      edge[u].push_back(i);
    }
  }

  queue<int> que;

  for(int i = 1 ; i <= n ; i++){
    if(ind[i]) continue;
    que.push(i);
    ans[i] = cost[i];
  }

  int cnt = 0;
  while(!que.empty()){
    int cur = que.front();
    que.pop();

    cnt = max(cnt,ans[cur]);

    for(int i = 0 ; i < edge[cur].size() ; i++){
      int next = edge[cur][i];
      ans[next] = max(ans[next],ans[cur] + cost[next]);
      if(--ind[next] == 0) que.push(next);
    }
  }

  cout << cnt << '\n';
  return 0;
}
