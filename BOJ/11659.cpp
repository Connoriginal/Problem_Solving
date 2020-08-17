#include <iostream>
#include <cstdio>

using namespace std;

int a[100001],sum[100001];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
    sum[i] = sum[i-1] + a[i];
  }

  while(m--){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",sum[b] - sum[a-1]);
  }
  return 0;
}
