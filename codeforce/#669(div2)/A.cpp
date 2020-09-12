#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;


      int one = 0 , zero = n;
      for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        if(arr[i] == 1) one++;
      }

      zero -= one;

      if(one > zero){
        if(one % 2 == 1) one--;
        cout << one << '\n';
        for(int i = 0 ; i < one ; i++) cout << 1 << ' ';
        cout << '\n';
      }else{
        cout << zero << '\n';
        for(int i = 0 ; i < zero ; i++) cout << 0 << ' ';
        cout << '\n';
      }
    }
    return 0;
}
