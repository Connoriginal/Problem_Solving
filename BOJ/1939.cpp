#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int,int> > edge[10001];
bool check[10001];

bool solve(int from, int to, int mid){
  check[from] = true;
  if(from == to) return true;

  for(auto &u : edge[from]){
    int next = u.first;
    int w = u.second;
    if(w >= mid && !check[next]){
      if(solve(next,to,mid)) return true;
    }
  }
  return false;
}


int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    edge[u].push_back(make_pair(v,w));
    edge[v].push_back(make_pair(u,w));
  }
  int from,to;
  scanf("%d %d",&from,&to);

  int l = 1, r = 1000000000;
  int ans = 0;

  while(l <= r){
    memset(check,false,sizeof(check));
    int mid = (l+r)/2;
    if(solve(from,to,mid)){
      l = mid + 1;
      ans = mid;
    }
    else{
      r = mid - 1;
    }
  }

  printf("%d\n",ans);
  return 0;
}
