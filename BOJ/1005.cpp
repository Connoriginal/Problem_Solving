#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;

    vector<int> build(n+1), in(n+1,0), cost(n+1,0);
    vector<vector<int> > edge(n+1);

    for(int i = 1 ; i <= n ; i++) cin >> build[i];

    while(k--){
      int u,v;
      cin >> u >> v;
      edge[u].push_back(v);
      in[v]++;
    }

    int last;
    cin >> last;

    queue<int> que;
    for(int i = 1 ; i <= n ; i++){
      if(in[i]) continue;
      que.push(i);
      cost[i] = build[i];
    }

    while(!que.empty()){
      int cur = que.front();
      que.pop();
      if(cur == last){
        cout << cost[cur] << '\n';
        break;
      }

      for(int i = 0 ; i < edge[cur].size() ; i++){
        int next = edge[cur][i];
        cost[next] = max(cost[next],cost[cur] + build[next]);
        if(--in[next] == 0) que.push(next);
      }
    }
  }
  return 0;
}
