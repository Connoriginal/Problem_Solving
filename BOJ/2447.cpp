#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N;

void solve(int x,int y, int N,int** map){
	if(N==1){
		map[x][y] = 1;
		return;
	}
	int next = N/3;
	solve(x,y,next,map);
	solve(x,y+next,next,map);
	solve(x,y+2*next,next,map);
	solve(x+next,y,next,map);
	solve(x+next,y + 2*next,next,map);
	solve(x + 2*next,y,next,map);
	solve(x + 2*next,y + next, next,map);
	solve(x + 2*next,y + 2*next,next,map);
}
int main(void){
	scanf("%d",&N);
	int ** map;
	map = (int **)malloc(sizeof(int*)*N);
	for(int i = 0 ; i < N ; i++)
		map[i] = (int *)malloc(sizeof(int)*N);
	solve(0,0,N,map);

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(map[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

/* 메모리많지만 속도 빠름
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char ans[6562][6562];

void go(int x, int y, int len){
  if(len == 3){
    for(int i = x ; i < x + 3 ; i++){
      for(int j = y ; j < y + 3 ; j++){
        if(i == x + 1 && j == y + 1) continue;
        ans[i][j] = '*';
      }
    }
    return;
  }

  int l = len/3;
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ; j++){
      if(i == 1 && j == 1) continue;
      go(x + i*l, y + j*l, l);
    }
  }
}

int main(void){
  int n;
  scanf("%d",&n);

  go(0,0,n);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(ans[i][j] == '*'){
        printf("*");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
*/
