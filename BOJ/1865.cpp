#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e11;
int n,m,w;
long long dist[501];

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    fill(&dist[0],&dist[500],INF);

    scanf("%d %d %d",&n,&m,&w);

    vector<vector<pair<int,long long> > > edge(n+1);
    for(int i = 0 ; i < m ; i++){
      int s,e;
      long long w;
      scanf("%d %d %lld",&s,&e,&w);
      edge[s].push_back(make_pair(e,w));
      edge[e].push_back(make_pair(s,w));
    }

    for(int i = 0 ; i < w ; i++){
      int s,e;
      long long w;
      scanf("%d %d %lld",&s,&e,&w);
      edge[s].push_back(make_pair(e,-w));
    }

    dist[1] = 0;
    bool flag = false;

    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        for(int q = 0 ; q < edge[j].size() ; q++){
          int next = edge[j][q].first;
          long long cst = edge[j][q].second;
          if(dist[next] > dist[j] + cst){
            dist[next] = dist[j] + cst;

            if(i == n){
              flag = true;
              break;
            }
          }
        }
      }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");

  }
  return 0;
}
