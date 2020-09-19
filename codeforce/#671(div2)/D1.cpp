#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    if(n%2 == 0){
      cout << (n-1)/2 << '\n';
    }else{
      cout << n/2 << '\n';
    }

    int i = 0;
    int j = n/2;
    while(j < n || i < n/2){
      if(j < n) cout << arr[j++] << ' ';
      if(i < n/2) cout << arr[i++] << ' ';
    }
    cout << '\n';
    return 0;
}
