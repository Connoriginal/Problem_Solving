#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool d[2502][2502];
int ans[2502];

int main(void){
  string a;
  cin >> a;

  int len = a.size();
  a = " " + a;

  for(int i = 1; i <= len ; i++){
    d[i][i] = true;
    if(i < len && a[i] == a[i+1]){
      d[i][i+1] = true;
    }
  }

  for(int k = 2 ; k < len ; k++){
    for(int i = 1 ; i < len - k + 1 ; i++){
      if(a[i] == a[i+k] && d[i+1][i+k-1]){
        d[i][i+k] = true;
      }
    }
  }

  ans[0] = 0;
  for(int i = 1 ; i <= len ; i++){
    ans[i] = -1;
    for(int j = 1 ; j <= i ; j++){
      if(d[j][i]){
        if(ans[i] == -1 || ans[i] > ans[j-1] + 1){
          ans[i] = ans[j-1] + 1;
        }
      }
    }
  }

  printf("%d\n",ans[len]);
  return 0;
}
