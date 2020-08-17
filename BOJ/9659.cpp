#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  long long n;
  scanf("%lld",&n);

  if(n&1) printf("SK\n");
  else printf("CY\n");
  return 0;
}
