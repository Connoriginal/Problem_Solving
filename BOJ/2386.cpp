#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main(void){
  char c;
  while(scanf("%c",&c) && c != '#'){
    int cnt = 0;

    char p;
    while(scanf("%c",&p)&& p != '\n'){
      if('A' <= p && p <= 'Z') p += 'a' - 'A';

      if(c == p) cnt++;
    }
    printf("%c %d\n",c,cnt);
  }
  return 0;
}
