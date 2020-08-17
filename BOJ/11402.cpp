#include <iostream>
#include <vector>

using namespace std;

int d[2001][2001];

int main(void){
  long long n,k;
  int m;
  scanf("%lld %lld %d",&n,&k,&m);

  d[0][0] = 1;
  for(int i = 1 ; i <= m ; i++){
    d[i][0] = 1; d[i][i] = 1;
    for(int j = 1 ; j < i ; j++){
      d[i][j] = d[i-1][j-1] + d[i-1][j];
      d[i][j] %= m;
    }
  }

  vector<int> a,b;
  long long ans = 1;

  while(n>0 || k > 0){
    a.push_back(n%m);
    b.push_back(k%m);
    n/=m;
    k/=m;
  }

  for(int i = 0 ; i < a.size() ; i++){
    ans *= d[a[i]][b[i]];
    ans %= m;
  }
  printf("%lld\n",ans);
  return 0;
}
