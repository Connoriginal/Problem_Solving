#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[51][12];
int b[12], c[12];
int n;

int play(int inning, int start){
  if(inning > n) return 0;

  int outcnt = 0, score = 0;
  bool base[4]={false,};
  int cur = start;

  while(outcnt < 3){
    if(a[inning][b[c[cur]]] == 0){
      outcnt++;
    }else if(a[inning][b[c[cur]]] == 1){
      for(int i = 3 ; i > 0 ; i--){
        if(base[i] && i < 3){
          base[i+1] = true;
          base[i] = false;
        }else if(base[i] && i == 3){
          score++;
          base[i] = false;
        }
      }
      base[1] = true;
    }else if(a[inning][b[c[cur]]] == 2){
      for(int i = 3 ; i > 0 ; i--){
        if(base[i] && i >= 2){
          score++;
          base[i] = false;
        }else if(base[i]){
          base[i+2] = true;
          base[i] = false;
        }
      }
      base[2] = true;
    }else if(a[inning][b[c[cur]]] == 3){
      for(int i = 3 ; i > 0 ; i--){
        if(base[i]) score++;
        base[i] = false;
      }
      base[3] = true;
    }else if(a[inning][b[c[cur]]] == 4){
      for(int i = 3 ; i > 0 ; i--){
        if(base[i]) score++;
        base[i] = false;
      }
      score++;
    }

    cur++;
    if(cur > 9) cur = 1;
  }

  return score + play(inning+1, cur);
}


int main(void){
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j < 10 ; j++){
      scanf("%d",&a[i][j]);
    }
  }

  for(int i = 1; i <= 9 ; i++){
    b[i] = i;
    if(i == 4) c[i] = 1;
    else if(i > 4) c[i] = i;
    else c[i] = i+1;
  }

  int ans = 0;
  while(true){
    ans = max(ans, play(1,1));
    if(!next_permutation(b+2,b+10)) break;
  }

  printf("%d\n",ans);
  return 0;
}
