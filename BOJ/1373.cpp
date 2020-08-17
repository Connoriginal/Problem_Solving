#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;


int main(void){
  string str;
  cin >> str;
  int len = str.size();

  if(len%3 == 2){
    printf("%d",(str[0]-'0')*2 + str[1] - '0');
  }
  else if(len % 3 == 1){
    printf("%d",str[0] - '0');
  }
  for(int i = len%3 ; i < len ; i += 3){
    printf("%d",(str[i]-'0')*4 + (str[i+1]-'0')*2 + str[i+2] - '0');
  }

  printf("\n");
}
