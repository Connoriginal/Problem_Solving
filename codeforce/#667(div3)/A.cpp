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
      int a,b;
      cin >> a >> b;

      if(a == b){
        cout << 0 << '\n';
        continue;
      }

      if(a > b){
        swap(a,b);
      }

      long long ans = (b-a) / 10;
      if((a%10) != (b%10)) ans++;

      cout << ans << '\n';
    }
    return 0;
}
