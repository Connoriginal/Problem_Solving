#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[11];
char b[10];
int n;

int cal(void){
  int ans = a[0];
  for(int i = 1 ; i < n ; i++){
    if(b[i-1] == 'a') ans += a[i];
    else if(b[i-1] == 'b') ans -= a[i];
    else if(b[i-1] == 'c') ans *= a[i];
    else if(b[i-1] == 'd') ans /= a[i];
  }
  return ans;
}

int main(void){
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }


  int p = 0;
  for(int i = 0 ; i < 4 ; i++){
    int temp;
    scanf("%d",&temp);
    for(int j = 0 ; j < temp ; j++){
      b[p++] = i + 'a';
    }
  }

  int ans_max = cal();
  int ans_min = ans_max;

  while(next_permutation(b,b+n-1)){
    int temp = cal();
    ans_max = (ans_max > temp) ? ans_max : temp;
    ans_min = (ans_min > temp) ? temp : ans_min;
  }

  printf("%d\n%d\n",ans_max,ans_min);

  return 0;
}
