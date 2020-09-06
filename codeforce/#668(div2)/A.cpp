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

      reverse(arr.begin(),arr.end());

      for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
      cout << '\n';

    }
    return 0;
}
