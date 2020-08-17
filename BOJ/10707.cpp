#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int a,b,c,d,p;
  scanf("%d %d %d %d %d",&a,&b,&c,&d,&p);

  int ans = b;
  if(p > c) ans += (p-c) * d;

  ans = min(ans,a*p);

  printf("%d\n",ans);
  return 0;
}
