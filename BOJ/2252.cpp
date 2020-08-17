#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin >> n >> m;

  vector<int> ind(n+1,0);
  vector<vector<int> > edge(n+1);

  while(m--){
    int u,v;
    cin >> u >> v;

    edge[u].push_back(v);
    ind[v]++;
  }

  queue<int> que;
  for(int i = 1 ; i <= n ; i++){
    if(!ind[i]) que.push(i);
  }

  while(!que.empty()){
    int cur = que.front();
    que.pop();

    cout << cur << " ";
    for(int i = 0 ; i < edge[cur].size() ; i++){
      int next = edge[cur][i];
      if(--ind[next] == 0) que.push(next);
    }
  }
  cout << '\n';
  return 0;
}
