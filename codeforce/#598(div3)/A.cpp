//solved
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int q;

int main(void){
  scanf("%d",&q);
  while(q--){
    int a,b,n,s;
    scanf("%d %d %d %d",&a,&b,&n,&s);

    bool ans = true;

    int top = s/n;
    int low;
    if(s-b >= 0){
      low = ((s-b)%n == 0)? (s-b)/n : (s-b)/n + 1;
    }
    else{
      low = (s-b)/n;
    }
    if(top < 0 || low > a || top < low) ans = false;

    if(ans){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }

  return 0;
}
