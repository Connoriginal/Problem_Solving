#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  long long s;
  scanf("%lld",&s);

  long long ans = 0, i = 1;
  while(s >= 0){
    s -= i++;
    ans++;
  }
  printf("%lld\n",ans-1);
  return 0;
}
