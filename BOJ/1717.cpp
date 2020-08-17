#include <iostream>
#include <cstdio>

using namespace std;

int parent[1000001];

int Find(int x){
  if(x == parent[x]) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
  x = Find(x);
  y = Find(y);
  parent[y] = x;
}

int main(void){
  int n, m;
  scanf("%d %d",&n,&m);

  for(int i = 0 ; i <= n ; i++) parent[i] = i;

  while(m--){
    int op,a,b;
    scanf("%d %d %d",&op,&a,&b);
    if(op){
      if(Find(a) == Find(b)) printf("YES\n");
      else printf("NO\n");
    }
    else{
      Union(a,b);
    }
  }
  return 0;
}
