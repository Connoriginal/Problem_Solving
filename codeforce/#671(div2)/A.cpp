#include <iostream>
#include <string>
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

      string str;
      cin >> str;

      int len = str.size();
      int len_odd = 0, len_even = 0;

      if(len % 2 == 1){
        for(int i = 0 ; i < len ; i+=2){
          int cur = str[i] - '0';
          if(cur % 2 == 0) len_even++;
          else len_odd++;
        }
        int cnt = len_odd + len_even;
        if(len_even > cnt-1) cout << 2 << '\n';
        else cout << 1 << '\n';
      }else{
        for(int i = 1 ; i < len ; i+=2){
          int cur = str[i] - '0';
          if(cur % 2 == 0) len_even++;
          else len_odd++;
        }
        int cnt = len_odd + len_even;
        if(len_odd > cnt-1) cout << 1 << '\n';
        else cout << 2 << '\n';
      }


    }
    return 0;
}
