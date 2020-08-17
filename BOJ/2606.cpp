//dfs 사용
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[101];
bool check[101];

int ans = 0;

void dfs(int x){
  check[x] = true;
  for(int i = 0 ; i < edge[x].size() ; i++){
    if(!check[edge[x][i]]){
      ans++;
      dfs(edge[x][i]);
    }
  }
}

int main(void){
  int n;
  scanf("%d",&n);

  int m;
  scanf("%d",&m);
  while(m--){
    int u,v;
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  dfs(1);
  printf("%d\n",ans);
  return 0;
}

/* 유니온 파인드
#include <iostream>
#include <cstdio>

using namespace std;

int parent[101];

int find(int x){
  if(parent[x] == x) return x;
  else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
  x = find(x);
  y = find(y);
  parent[y] = x;
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++) parent[i] = i;

  int m;
  scanf("%d",&m);

  while(m--){
    int a,b;
    scanf("%d %d",&a,&b);
    uni(a,b);
  }

  int ans = 0;
  for(int i = 2 ; i <= n ; i++){
    if(find(1) == find(i)) ans++;
  }

  printf("%d\n",ans);
  return 0;
}
*/
