#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      long long x,y,k;
      cin >> x >> y >> k;

      long long ans = k;
      long long cnt = k*(y+1) - 1;

      ans += cnt/(x-1);
      if(cnt % (x-1) != 0){
        ans++;
      }

      cout << ans << '\n';
    }
    return 0;
}
