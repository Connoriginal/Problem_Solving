#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(3);

bool check(){
  for(int i = 0 ; i < 3 ; i++){
    if(arr[i] == 0) return false;
  }
  return true;
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){

    int w;
    for(int i = 0 ; i < 3 ; i++) cin >> arr[i];
    cin >> w;

    bool ans = false;

    for(int j = 0 ; j < 2 ; j++){
      int cnt = 0;
      for(int i = 0 ; i < 3 ; i++){
        if(arr[i] % 2 == 1) cnt++;
      }

      if(cnt == 0){
        ans = true;
        break;
      }else{
        if(cnt == 1 && w % 2 == 0){
          ans = true;
          break;
        }
        if(check()){
          for(int i = 0 ; i < 3 ; i++) arr[i]--;
          w += 3;
        }else{
          break;
        }
      }
    }

    if(ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}
