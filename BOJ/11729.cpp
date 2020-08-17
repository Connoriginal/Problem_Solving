#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void go(int from, int to, int num){
  if(num == 0) return;
  go(from,6-(from + to),num-1);
  printf("%d %d\n",from,to);
  go(6 - (from + to),to,num-1);
}
int main(void){
  int n;
  scanf("%d",&n);
  printf("%d\n",(2<<(n-1)) - 1);

  go(1,3,n);
  return 0;
}
