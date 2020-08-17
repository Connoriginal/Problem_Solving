#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF_LOW = -1e12;
const long long INF_MAX = 1e12;

long long earn[101];
long long dist[101];
bool visit[101];
vector<vector<pair<int,long long> > > edge(101);

void dfs(int s, int e){
  visit[s] = true;
  if(s == e) return;

  for(int i = 0 ; i < edge[s].size() ; i++){
    int next = edge[s][i].first;
    if(!visit[next]) dfs(next,e);
  }
  return;
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  fill(&dist[0],&dist[100],INF_LOW);

  int n,s,e,m;
  cin >> n >> s >> e >> m;

  for(int i = 0 ; i < m ; i++){
    int u,v;
    long long z;
    cin >> u >> v >> z;
    edge[u].push_back(make_pair(v,-z));
  }

  for(int i = 0 ; i < n ; i++) cin >> earn[i];

  dfs(s,e);
  if(!visit[e]){
    cout << "gg" << '\n';
    return 0;
  }

  dist[s] = earn[s];
  for(int i = 1 ; i < 2*n ; i++){
    for(int j = 0 ; j < n ; j++){
      for(int q = 0 ; q < edge[j].size() ; q++){
        int next = edge[j][q].first;
        long long cst = edge[j][q].second;
        if(dist[j] == INF_MAX) dist[next] = INF_MAX;
        else if(dist[j] != INF_LOW && dist[next] < dist[j] + cst + earn[next]){
          dist[next] = dist[j] + cst + earn[next];
          if(i >= n) dist[next] = INF_MAX;
        }
      }
    }
  }

  if(dist[e] == INF_MAX) cout << "Gee" << '\n';
  else cout << dist[e] << '\n';
  return 0;
}
