#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int mod = 1e9 + 7;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  long long minus = 4;

  long long mult = 1;
  long long ans = 1;
  for(int i = 1 ; i <= n ; i++){
    mult *= (i%mod);
    if(i > 3){
      minus *= 2;
    }
    ans = mult - minus;
    mult %= mod;
    minus %= mod;
  }

  cout << ans % mod << '\n';
  return 0;
}
