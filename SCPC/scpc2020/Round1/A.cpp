#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int test_case = 1 ; test_case <= t ; test_case++){
      int n,k;
      cin >> n >> k;

      vector<int> a(n), b(n);

      for(int i = 0 ; i < n ; i++) cin >> a[i];
      for(int i = 0 ; i < n ; i++) cin >> b[i];

      sort(a.begin(),a.end());
      sort(b.begin(),b.end());

      reverse(b.begin(), b.begin() + k);

      int ans = 0;
      for(int i = 0 ; i < k ; i++) ans = max(ans,a[i] + b[i]);

      cout << "Case #" << test_case << '\n';
      cout << ans << '\n';
    }
    return 0;
}
