#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int sum[1001];

int main(void){
  int n,q;
  scanf("%d %d",&n,&q);

  int prev,cur;
  scanf("%d",&prev);
  for(int i = 2 ; i <= n; i++){
    sum[i] = sum[i-1];
    scanf("%d",&cur);
    sum[i] += abs(cur - prev);
    prev = cur;
  }

  while(q--){
    int s,e;
    scanf("%d %d",&s,&e);
    if(e-1 < s) printf("0\n");
    else printf("%d\n",sum[e] - sum[s]);
  }

  return 0;
}
