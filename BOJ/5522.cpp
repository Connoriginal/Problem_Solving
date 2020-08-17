#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int sum = 0;
  for(int i = 0 ; i < 5 ; i++){
    int tmp;
    scanf("%d",&tmp);
    sum += tmp;
  }
  printf("%d\n",sum);
  return 0;
}
