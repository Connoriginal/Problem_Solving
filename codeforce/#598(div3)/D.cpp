//solved
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


int main(void){
  int q;
  scanf("%d",&q);
  while(q--){
    int n;
    long long k;
    scanf("%d %lld",&n,&k);

    string str;
    cin >> str;

    string ans;


    int cnt = 0;
    bool printed = false;
    for(int i = 0 ; i < n ; i++){
      if(str[i] == '0'){
        if(cnt <= k){
          ans += '0';
          k -= cnt;
        }

        else{
          ans += string(cnt - k,'1');
          ans += '0';
          ans += string(k,'1');
          ans += str.substr(i+1);
          cout << ans << '\n';
          printed = true;
          break;
        }
      }
      else{
        cnt++;
      }
    }

    if(!printed){
      ans += string(cnt,'1');
      cout << ans << '\n';
    }

  }
  return 0;
}
