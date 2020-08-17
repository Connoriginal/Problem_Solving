#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int a[101];

int main(void){
  scanf("%d %d",&n,&m);

  vector<vector<int> > edge(n+1);

  for(int i = 0 ; i < m ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  int ans = 0;
  int sum = 100000;

  for(int i = 1 ; i <= n ; i++){
    memset(a,-1,sizeof(a));

    queue<int> que;
    que.push(i);
    a[i] = 0;
    while(!que.empty()){
      int cur = que.front();
      que.pop();
      for(int j = 0 ; j < edge[cur].size() ; j++){
        if(a[edge[cur][j]] == -1 || a[cur] + 1 < a[edge[cur][j]]){
          a[edge[cur][j]] = a[cur] + 1;
          que.push(edge[cur][j]);
        }
      }
    }

    int temp = 0;
    for(int j = 1 ; j <= n ; j++) temp += a[j];
    if(temp < sum){
      ans = i;
      sum = temp;
    }
  }

  printf("%d\n",ans);
  return 0;
}
