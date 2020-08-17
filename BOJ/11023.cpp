#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int tmp;
  scanf("%d",&tmp);
  int sum = tmp;
  while(getchar() != '\n'){
    scanf("%d",&tmp);
    sum += tmp;
  }
  printf("%d\n",sum);
  return 0;
}
