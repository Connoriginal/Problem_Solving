#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  if(n&1) printf("SK\n");
  else printf("CY\n");
  return 0;
}
