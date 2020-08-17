#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

int t;

int main(void){
  scanf("%d",&t);
  while(t--){
    long long n,m;
    scanf("%lld %lld",&n,&m);

    n = n/m;
    vector<int> cycle(10);
    for(int i = 0 ; i < 10 ; i++){
      cycle[i] = ((i+1)*m)%10;
    }

    long long sum = 0;
    for(int i = 0 ; i < n%10 ; i++){
      sum += cycle[i];
    }
    
    sum += n/10 * accumulate(cycle.begin(),cycle.end(),0LL);
    printf("%lld\n",sum);
  }
  return 0;
}
