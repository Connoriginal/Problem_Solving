#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    int plyr1 = 0, plyr2 = 0;
    while(n--){
      char a,b;
      scanf(" %c %c",&a,&b);
      if(a == b) continue;

      if(a == 'R'){
        if(b == 'P') plyr2++;
        else if(b == 'S') plyr1++;
      }else if(a == 'P'){
        if(b == 'R') plyr1++;
        else if(b == 'S') plyr2++;
      }else{
        if(b == 'P') plyr1++;
        else if(b == 'R') plyr2++;
      }
    }
    if(plyr1 > plyr2) printf("Player 1\n");
    else if(plyr1 == plyr2) printf("TIE\n");
    else printf("Player 2\n");
  }
  return 0;
}
