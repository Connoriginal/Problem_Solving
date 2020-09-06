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
      int n;
      cin >> n;

      vector<int> arr(n);
      for(int i = 0 ; i < n ; i++) cin >> arr[i];

      for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] <= 0) continue;

        for(int j = i+1 ; j < n ; j++){
          if(arr[i] <= 0) break;

          if(arr[j] < 0){
            if(arr[i] + arr[j] <= 0){
              arr[j] += arr[i];
              arr[i] = 0;
            }else{
              arr[i] += arr[j];
              arr[j] = 0;
            }
          }

        }
      }

      long long ans = 0;
      for(int i = 0 ; i < n ; i++){
        if(arr[i] >= 0) ans += arr[i];
      }

      cout << ans << '\n';
    }
    return 0;
}
