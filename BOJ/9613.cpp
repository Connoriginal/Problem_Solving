#include <iostream>
#include <cstdio>


using namespace std;

int arr[101];

int gcd(int a,int b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&arr[i]);
    }

    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
      for(int j = i + 1 ; j < n ; j++){
        ans += gcd(arr[i],arr[j]);
      }
    }
    printf("%llu\n",ans);
  }
}
