#include <iostream>
#include <cstdio>

using namespace std;

int a[5][8];

void rotate(int num, int dir){
  int b[8];
  if(dir == 1){
    for(int i = 0 ; i < 7 ; i++){
      b[i+1] = a[num][i];
    }
    b[0] = a[num][7];
  }else{
    for(int i = 1 ; i < 8  ; i++){
      b[i-1] = a[num][i];
    }
    b[7] = a[num][0];
  }

  for(int i = 0 ; i < 8 ; i++){
    a[num][i] = b[i];
  }
  return;
}


int main(void){
  for(int i = 1 ; i <= 4 ; i++){
    for(int j = 0 ; j < 8 ; j++){
      scanf("%1d",&a[i][j]);
    }
  }

  int k;
  scanf("%d",&k);

  while(k--){
    int num,dir;
    scanf("%d %d",&num,&dir);

    int flag[5];

    flag[num] = dir;
    for(int i = num ; i < 4 ; i++){
      if(a[i][2] != a[i+1][6]) flag[i+1] = 0 - flag[i];
      else flag[i+1] = 0;
    }

    for(int i = num ; i > 1 ; i--){
      if(a[i][6] != a[i-1][2]) flag[i-1] = 0 - flag[i];
      else flag[i-1] = 0;
    }

    for(int i = 1 ; i <= 4 ; i++){
      if(flag[i] != 0){
        rotate(i,flag[i]);
      }
    }
  }

  int ans = 0;
  for(int i = 1 ; i <= 4 ; i++){
    ans += (a[i][0] << (i-1));
  }
  printf("%d\n",ans);
  return 0;
}
