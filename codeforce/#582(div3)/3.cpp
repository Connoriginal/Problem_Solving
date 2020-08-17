#include <iostream>
#include <cstdio>


using namespace std;

int t;


int main(void){
  scanf("%d",&t);
  while(t--){
    long long n,m;
    long long ans = 0;
    scanf("%lld %lld",&n,&m);
    int tmp = m%10;
    int alp = tmp;
    long long sum = tmp;
    for(int i = 1 ; i < 10 ; i++){
      alp += tmp;
      alp %= 10;
      sum += alp;
    }

    ans = ((n/m)/10)*sum;
    for(int i = 0 ; i < (n/m)%10 ; i++){
      alp += tmp;
      alp %= 10;
      ans += alp;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
