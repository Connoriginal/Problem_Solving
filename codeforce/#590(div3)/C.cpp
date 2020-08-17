#include <iostream>
#include <cstdio>

using namespace std;

int map[2][200001];

int main(void){
  int q;
  scanf("%d",&q);
  while(q--){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < 2 ; i++){
      for(int j = 0 ; j < n ; j++){
        scanf("%1d",&map[i][j]);
      }
    }

    int height = 0;
    int len = 0;
    bool ans = true;

    for(; len < n ; len++){
      if(3 <= map[height][len] && map[height][len] <= 6){
        height = 1 - height;
        if(1 <= map[height][len] && map[height][len] <= 2){
          ans = false;
          break;
        }
      }
    }

    if(!ans){
      printf("NO\n");
    }
    else{
      if(height == 1){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }

  }
  return 0;
}
