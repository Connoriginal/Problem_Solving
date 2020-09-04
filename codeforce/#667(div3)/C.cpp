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
      int n,x,y;
      cin >> n >> x >> y;

      int check;
      for(int i = 1 ; i <= y-x ; i++){
        if(i * n < y-x+1) continue;

        if((y-x) % i == 0){
          check = i;
          break;
        }
      }

      int cnt = 1;
      int ans = y;
      int cur = y;
      bool flag = false;

      cout << cur << " ";
      while(cnt < n){
        if(cur - check <= 0){
          flag = true;
          cur = y;
        }
        if(flag){
          cur += check;
        }else{
          cur -= check;
        }
        cout << cur << " ";
        cnt++;
      }
      cout << '\n';

    }
    return 0;
}
