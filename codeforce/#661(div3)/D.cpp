#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    string ans = "";
    string str;
    cin >> str;

    int size = 0;
    deque<int> dqz,dqo;
    for(int i = 0 ; i < str.size() ; i++){
      int tmp = str[i] - '0';

      if(size == 0){
        ans += to_string(++size) + " ";
        if(tmp == 1) dqo.push_back(1);
        else dqz.push_back(1);
      }else{
        if(tmp == 1){
          if(!dqz.empty()){
            ans += to_string(dqz.front()) + " ";
            dqo.push_back(dqz.front());
            dqz.pop_front();
          }else{
            dqo.push_back(++size);
            ans += to_string(size) + " ";
          }
        }else{
          if(!dqo.empty()){
            ans += to_string(dqo.front()) + " ";
            dqz.push_back(dqo.front());
            dqo.pop_front();
          }else{
            dqz.push_back(++size);
            ans += to_string(size) + " ";
          }
        }
      }
    }

    cout << size << '\n' << ans << '\n';

  }
  return 0;
}
