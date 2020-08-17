#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    int len;
    if(n%4 == 0) len = n/4;
    else len = (n/4) + 1;

    for(int i = 0 ; i < n - len ; i++) printf("9");
    for(int i = 0 ; i < len ; i++) printf("8");
    printf("\n");
  }
  return 0;
}
