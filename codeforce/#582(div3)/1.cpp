#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main(void){
  int odd = 0;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    int tmp;
    scanf("%d",&tmp);
    odd += tmp & 1;
  }

  printf("%d\n",min(odd,n - odd));

  return 0;
}
