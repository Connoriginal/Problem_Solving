#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int compli[100001] = {0,};
int parent[100001];

int main(void){
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    int tmp;
    scanf("%d",&tmp);
    parent[i] = tmp;
  }

  while(m--){
    int u,v;
    scanf("%d %d",&u,&v);
    compli[u] += v;
  }

  for(int i = 1 ; i <= n ; i++){
    if(parent[i] != -1){
      compli[i] += compli[parent[i]];
    }
    printf("%d ",compli[i]);
  }
  printf("\n");
  return 0;
}
