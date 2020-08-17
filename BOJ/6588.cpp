#include <iostream>
#include <cstdio>

using namespace std;

bool prime[1000001];

int main(void){
  prime[1] = true;
  for(int i = 2 ; i <= 1000000 ; i++){
    if(prime[i]) continue;
    for(int j = i*2 ; j <= 1000000 ; j+=i){
      prime[j] = true;
    }
  }

  while(true){
    int n;
    scanf("%d",&n);
    if(n == 0) break;

    bool check = false;
    for(int i = 3 ; i*2 <= n ; i+=2){
      if(!prime[i] && !prime[n-i]){
        printf("%d = %d + %d\n",n,i,n-i);
        check = true;
        break;
      }
    }

    if(!check){
      printf("Goldbach's conjecture is wrong.\n");
    }
  }
  return 0;
}
