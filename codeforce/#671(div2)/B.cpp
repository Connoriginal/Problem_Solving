#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      long long x;
      cin >> x;

      long long ans = 0;
      long long stair = 1;
      while(x > 0){
        long long next = stair * (stair+1) / 2;
        stair+=(stair+1);
        if(x < next) break;

        ans++;
        x -= next;
      }

      cout << ans << '\n';
    }
    return 0;
}
