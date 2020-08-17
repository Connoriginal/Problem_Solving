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

char map[3073][6145];
int N;

void solve(int x, int y, int n){
	if(n==1){
		map[x][y] = '*';
		return;
	}
	if(n==3){
		solve(x,y,1);
		solve(x+1,y-1,1);
		solve(x+1,y+1,1);
		for(int i = 0 ; i < 5 ; i++)
			solve(x+2,y+i-2,1);
	}
	else{
		solve(x,y,n/2);
		solve(x + n/2, y - (n/2), n/2);
		solve(x + n/2, y + (n/2), n/2);
	}
}
int main(void){
	scanf("%d",&N);
	memset(map,' ',sizeof(map));

	solve(0,N-1,N);

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < 2*N ; j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void go(int x, int y, int len, int** map){
  if(len == 3){
    map[x][y+2] = 1;
    map[x+1][y+1] = 1;
    map[x+1][y+3] = 1;
    for(int i = 0 ; i < 5 ; i++){
      map[x+2][y+i] = 1;
    }
    return;
  }

  int l = len/2;
  go(x, y + l, l, map);
  go(x+l, y, l, map);
  go(x+l, y + len, l, map);
  return;
}

int main(void){
  int n;
  scanf("%d",&n);

  int ** map;
  map = (int**)malloc(sizeof(int *)*n);
  for(int i = 0 ; i < n ; i++){
    map[i] = (int*)malloc(sizeof(int)*(2*n));
  }

  go(0,0,n,map);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < 2*n ; j++){
      if(map[i][j] == 1) printf("*");
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}
*/
