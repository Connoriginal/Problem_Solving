#include <iostream>
#include <cstdio>

using namespace std;

int a[101];
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++) a[i] = i;

  while(m--){
    int u,v;
    scanf("%d %d",&u,&v);
    swap(a[u],a[v]);
  }

  for(int i = 1 ; i <= n ; i++) printf("%d ",a[i]);
  printf("\n");
  return 0;
}
