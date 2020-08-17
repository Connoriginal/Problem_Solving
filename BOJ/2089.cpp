#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
  long long n;
  scanf("%lld",&n);

  if(n==0){
    printf("0\n");
    return 0;
  }

  vector<int> vec;

  while(n != 0){
    if(n > 0){
      vec.push_back(n%-2);
      n = n/-2;
    }
    else{
      vec.push_back(-n%-2);
      n = (n-1)/-2;
    }
  }

  while(!vec.empty()){
    printf("%d",vec.back());
    vec.pop_back();
  }
  printf("\n");
  return 0;
}
