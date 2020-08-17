#include <iostream>
#include <cstdio>

using namespace std;

int a[10];

int main(void){

  for(int i = 0 ; i < 9 ; i++){
    scanf("%d",&a[i]);
  }
  int f = 0, s = 0;
  for(int i = 0 ; i < 9 ; i++){
    f += a[i];
    if(f > s){
      printf("Yes\n");
      return 0;
    }
    int temp;
    scanf("%d",&temp);
    s += temp;
  }

  printf("No\n");
  return 0;
}
