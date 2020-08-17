#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    long long n;
    scanf("%lld",&n);

    if(n % 2 == 0){
      printf("%lld %lld\n",n/2,n/2);
    }
    else{
      long long a = 1;
      long long b = n-1;
      for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
          long long temp = n/i;
          a = temp;
          b = n - temp;
          break;
        }
      }
      printf("%lld %lld\n",a,b);
    }
  }
  return 0;
}
