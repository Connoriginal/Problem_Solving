#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int mod = 1000000;
int d[5001];

int main(void){
  string str;
  cin >> str;

  str = " " + str;
  d[0] = 1;

  for(int i = 1 ; i <= str.size() ; i++){
    int temp = str[i] - '0';
    if(0 < temp && temp < 10){
      d[i] += d[i-1];
      d[i] %= mod;
    }

    if(i == 1) continue;

    temp += (str[i-1] - '0')*10;

    if(10 <= temp && temp <= 26){
      d[i] += d[i-2];
      d[i] %= mod;
    }
  }

  printf("%d\n",d[str.size()-1]);
  return 0;
}
