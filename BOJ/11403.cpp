//Floyd-Warshall
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e5;

int n;
int dist[101][101];

int main(void){
  scanf("%d",&n);
  fill(&dist[0][0], &dist[100][100],INF);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      int tmp;
      scanf("%d",&tmp);
      if(tmp) dist[i][j] = tmp;
    }
  }

  //Floyd-Warshall
  for(int k = 1 ; k <= n ; k++){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      printf("%d ", (dist[i][j] == INF) ? 0 : 1);
    }
    printf("\n");
  }
  return 0;
}
