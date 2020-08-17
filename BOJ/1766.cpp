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

  priority_queue<int,vector<int>,greater<int> > pq;
  for(int i = 1 ; i <= n ; i++){
    if(ind[i]) continue;
    pq.push(i);
  }

  while(!pq.empty()){
    int cur = pq.top();
    cout << cur << " ";
    pq.pop();

    for(int i = 0 ; i < edge[cur].size() ; i++){
      int next = edge[cur][i];

      if(--ind[next] == 0) pq.push(next);
    }
  }
  cout << '\n';


  return 0;
}
