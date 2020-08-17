#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1001];
vector<int> edge(1001);

void dfs(int x){
  check[x] = true;
  int y = edge[x];
  if(!check[y]){
     dfs(y);
  }
}
int main(void){
  int t;
  scanf("%d",&t);

  while(t--){
    memset(check,false,sizeof(check));
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
      int tmp;
      scanf("%d",&tmp);
      edge[i] = tmp;
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
      if(!check[i]){
        dfs(i);
        ans++;
      }
    }

    printf("%d\n",ans);
  }
  return 0;
}
