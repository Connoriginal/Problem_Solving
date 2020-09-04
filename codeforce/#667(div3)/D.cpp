#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long pow(int x){
  long long ans = 1;
  while(x > 0){
    ans *= 10;
    x--;
  }
  return ans;
}

long long go(string str){
  long long ans = 0;
  for(int i = 0 ; i < str.size() ; i++){
    int cur = str[i] - '0';
    ans += cur;
  }
  return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      string n;
      long long s;
      cin >> n >> s;

      reverse(n.begin(),n.end());

      long long ans = 0;

      while(true){
        long long cnt = go(n);
        if(cnt <= s) break;

        int len = n.size();
        for(int i = 0 ; i < len ; i++){
          if(n[i] == '0') continue;

          int cur = n[i] - '0';
          n[i] = '0';
          if(i < n.size()-1){
            n[i+1] += 1;
          }else{
            n+="1";
          }
          ans += (10 - cur) * pow(i);
          break;
        }
      }

      cout << ans << '\n';
    }
    return 0;
}
