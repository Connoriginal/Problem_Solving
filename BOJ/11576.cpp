#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
  int a,b;
  scanf("%d %d",&a,&b);

  int len;
  scanf("%d",&len);

  int base = 0;

  while(len--){
    int tmp;
    scanf("%d",&tmp);
    base *= a;
    base += tmp;
  }

  vector<int> vec;
  while(base>0){
    vec.push_back(base%b);
    base /= b;
  }

  while(!vec.empty()){
    printf("%d ",vec.back());
    vec.pop_back();
  }

  printf("\n");
  return 0;
}
