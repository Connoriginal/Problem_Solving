#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<pair<int,int> > edge[10001];
int len[10001];

void bfs(int start){
  queue<int> que;
  que.push(start); len[start] = 0;
  while(!que.empty()){
    int x = que.front(); que.pop();
    for(int i = 0 ; i < edge[x].size() ; i++){
      int y = edge[x][i].first;
      int temp = edge[x][i].second;
      if(len[y] == -1){
        que.push(y);
        len[y] = len[x] + temp;
      }
    }
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n-1 ; i++){
    int from,at,temp;
    scanf("%d %d %d",&from,&at,&temp);
    edge[from].push_back(make_pair(at,temp));
    edge[at].push_back(make_pair(from,temp));
  }

  memset(len,-1,sizeof(len));

  bfs(1);

  int start;
  int m = 0;

  for(int i = 1 ; i <= n ; i++){
    if(len[i] > m){
      m = len[i];
      start = i;
    }
  }

  memset(len,-1,sizeof(len));

  bfs(start);

  int ans = 0;

  for(int i = 1 ; i <= n ; i++){
    ans = max(ans,len[i]);
  }

  printf("%d\n",ans);

  return 0;
}
