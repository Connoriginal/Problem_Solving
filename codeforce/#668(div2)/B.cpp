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

<<<<<<< HEAD
      vector<long long> arr(n+1), plus;

      for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        if(arr[i] > 0) plus.push_back(i);
      }

      if(!plus.size()){
        cout << 0 << '\n';
        continue;
      }

      int idx = plus[0] + 1;
      int pt = 0;

      while(idx < n){
        if(plus[pt] < idx && arr[idx] < 0){
          if(arr[plus[pt]] + arr[idx] <= 0){
            arr[idx] += arr[plus[pt]];
            arr[plus[pt]] = 0;
            pt++;
          }else{
            arr[plus[pt]] += arr[idx];
            arr[idx] = 0;
          }
        }else{
          idx++;
=======
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

>>>>>>> b6621f8f674cfd2876ad526b26a00f138380ebdf
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
