#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long go(long long a, long long b, long long x, long long y, long long n){
  if(a-x <= n){
    n -= a-x;
    a = x;
  }else{
    a -= n;
    n = 0;
  }

  if(b-y <= n){
    b = y;
  }else{
    b -= n;
  }

  return a * b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      long long a,b,x,y,n;
      cin >> a >> b >> x >> y >> n;

      if((a-x) + (b-y) <= n){
        cout << x * y << '\n';
        continue;
      }

      long long ans = min(go(a,b,x,y,n),go(b,a,y,x,n));

      cout << ans << '\n';
    }
    return 0;
}
