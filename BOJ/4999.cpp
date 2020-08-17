#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(void){
  string a, b;
  cin >> a >> b;
  if(a.size() >= b.size()) printf("go\n");
  else printf("no\n");
  return 0;
}
