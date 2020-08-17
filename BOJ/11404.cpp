#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e8;

int dist[101][101];

int main(void){
  fill(&dist[0][0],&dist[100][100],INF);

  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++) dist[i][i] = 0;

  while(m--){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    dist[u][v] = min(dist[u][v],w);
  }

  for(int k = 1 ; k <= n ; k++){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
      }
    }
  }

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      printf("%d ",(dist[i][j] == INF) ? 0 : dist[i][j]);
    }
    printf("\n");
  }
  return 0;
}
