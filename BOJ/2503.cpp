#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool check[1000];

int get_strike(int a, int b){
  int ans = 0;
  while(a>0){
    if(a%10 == b%10) ans++;
    a /= 10;
    b /= 10;
  }
  return ans;
}

int get_ball(int a, int b){
  int ans = 0;
  for(int i = 0 ; i < 3 ; i++){
    int tmp = a;
    for(int j = 0 ; j < 3 ; j++){
      if(i!=j && (tmp % 10 == b%10)){
        ans++;
      }
      tmp /= 10;
    }
    b /= 10;
  }
  return ans;
}

int main(void){
  int n;
  scanf("%d",&n);

  //물어볼 수 있는 수 true 로 만들기
  for(int i = 1 ; i < 10 ; i++){
    for(int j = 1 ; j < 10 ; j++){
      for(int k = 1 ; k < 10 ; k++){
        if(i != j && j != k && k != i){
          check[100*i + 10*j + k] = true;
        }
      }
    }
  }

  while(n--){
    int qt, sn, bn;
    scanf("%d %d %d",&qt,&sn,&bn);

    for(int i = 123 ; i <= 987 ; i++){
      if(check[i]){
        if(get_strike(i,qt) != sn){
          check[i] = false;
          continue;
        }
        if(get_ball(i,qt) != bn){
          check[i] = false;
          continue;
        }
      }
    }

  }

  int ans = 0;
  for(int i = 123 ; i <= 987 ; i++){
    if(check[i]) ans++;
  }

  printf("%d\n",ans);
  return 0;
}
