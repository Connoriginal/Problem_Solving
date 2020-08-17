#include <iostream>
#include <cstdio>

using namespace std;

const int maximum = 100001;

int d[100001];

int main(void){
  int n;
  scanf("%d",&n);

  d[1] = 1;

  for(int i = 2 ; i <= n ; i++){
    d[i] = maximum;
    for(int j = 1 ; j*j <= i ; j++){
      if(d[i] > d[i-(j*j)] + 1){
        d[i] = d[i-(j*j)] + 1;
      }
    }
  }

  printf("%d\n",d[n]);
  return 0;
}
