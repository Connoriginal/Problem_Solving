#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int ans = 0;
  char prev, cur;

  scanf("%c", &prev);
  while(true){
    scanf("%c", &cur);
    if(cur != '0' && cur != '1') break;

    if(prev != cur){
      ans++;
      prev = cur;
    }
  }

  if(ans % 2 == 1) ans = ans/2 + 1;
  else ans = ans/2;

  printf("%d\n",ans);
  return 0;
}
