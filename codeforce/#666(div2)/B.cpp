#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>


using namespace std;

int n;

long long go(int x, vector<long long> arr){
  long long sum = 0;
  long long cur = 1;
  for(int i = 0 ; i < n ; i++){
    if(cur > arr[i]) sum += cur - arr[i];
    else sum += arr[i] - cur;
    cur *= x;
  }
  return sum;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<long long> arr(n);

    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    double top = (double)arr[n-1];

    long long cur = 1;
    long long ans = go(cur,arr);

    if(n <= 63){
      while(pow(cur,n-1) < top){
        cur++;
        ans = min(ans,go(cur,arr));
      }
    }

    cout << ans << '\n';
    return 0;
}
