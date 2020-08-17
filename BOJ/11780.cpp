#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 1e11;

int n,m;
long long dist[101][101];
int path[101][101];

int cnt;

string go(int s, int e){
  if(path[s][e]){
    cnt++;
    return go(s,path[s][e]) + to_string(path[s][e]) + go(path[s][e],e);
  }else{
    return " ";
  }
}

int main(void){
  fill(&dist[0][0],&dist[100][100],INF);

  scanf("%d %d",&n,&m);

  for(int i = 0 ; i <= n ; i++) dist[i][i] = 0;

  for(int i = 0 ; i < m ; i++){
    long long u,v,z;
    scanf("%lld %lld %lld",&u,&v,&z);
    dist[u][v] = min(dist[u][v],z);
  }


  for(int k = 1 ; k <= n ; k++){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        if(dist[i][k] + dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = k;
        }
      }
    }
  }

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      printf("%lld ",dist[i][j] == INF ? 0 : dist[i][j]);
    }
    printf("\n");
  }

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      if(dist[i][j] == INF || dist[i][j] == 0){
        printf("0\n");
      }else{
        cnt = 2;
        string str = to_string(i) + go(i,j) + to_string(j);
        cout << cnt << " " << str << '\n';
      }
    }
  }
  return 0;
}
