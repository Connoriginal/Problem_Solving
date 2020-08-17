//Bellman-Ford
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1e9;

int n,m;

int main(void){
  scanf("%d %d",&n,&m);

  vector<vector<pair<int,int> > > edge(n+1);

  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    edge[u].push_back(make_pair(v,w));
  }

  vector<long long> dist(n+1,INF);
  dist[1] = 0;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      for(int q = 0 ; q < edge[j].size() ; q++){
        int next = edge[j][q].first;
        long long cost = edge[j][q].second;
        if(dist[j] != INF && dist[next] > dist[j] + cost){
          dist[next] = dist[j] + cost;
          if(i == n){
            printf("-1\n");
            return 0;
          }
        }
      }
    }
  }

  for(int i = 2 ; i <= n ; i++) printf("%lld\n",(dist[i] == INF) ? -1 : dist[i]);
  return 0;
}
/* SPFA
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
bool inque[501];
int update[501];

int n,m;

int main(void){
  scanf("%d %d",&n,&m);

  vector<vector<pair<int, int> > > edge(n+1);

  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    edge[u].push_back(make_pair(v,w));
  }

  vector<long long> dist(n+1,INF);
  queue<int> que;
  dist[1] = 0;
  que.push(1);
  inque[1] = true;

  while(!que.empty()){
    int cur = que.front();
    que.pop();
    inque[cur] = false;

    for(int i = 0 ; i < edge[cur].size() ; i++){
      int next = edge[cur][i].first;
      int cst = edge[cur][i].second;
      if(dist[next] > dist[cur] + cst){
        dist[next] = dist[cur] + cst;

        if(++update[next] >= n){
          printf("-1\n");
          return 0;
        }

        if(inque[next]) continue;

        que.push(next);
        inque[next] = true;
      }
    }
  }

  for(int i = 2 ; i <= n ; i++) printf("%lld\n",(dist[i] == INF) ? -1 : dist[i]);
  return 0;
}
*/
