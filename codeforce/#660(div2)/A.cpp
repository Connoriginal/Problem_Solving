#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    int num[3] = {6,10,14};

    if(n < 31) printf("NO\n");
    else{
      n -= 30;
      for(int i = 0 ; i < 3 ; i++){
        if(n == num[i]){
          num[2]++;
          n--;
          break;
        }
      }
      printf("YES\n");
      for(int i = 0 ; i < 3 ; i++) printf("%d ",num[i]);
      printf("%d\n",n);
    }
  }
  return 0;
}
