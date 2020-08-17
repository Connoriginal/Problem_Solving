#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(void){
  string str;
  int b;
  cin >> str >> b;

  int ans = 0;

  for(int i = 0 ; i < str.size() ; i++){
    ans *= b;
    if('0' <= str[i] && str[i] <= '9'){
      ans += str[i] - '0';
    }
    else{
      ans += str[i] - 'A' + 10;
    }
  }

  printf("%d\n",ans);
}
