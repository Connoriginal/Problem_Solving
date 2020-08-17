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
int ans[3]; //0은 -1,1은 0,2는 1개수
int paper[3000][3000];

bool check(int x,int y,int n){
	for(int i = x ; i < x + n ; i++){
		for(int j = y ; j < y + n ; j++){
			if(paper[x][y] != paper[i][j])
				return false;
		}
	}

	return true;
}

void solve(int x, int y, int n){
	if(check(x,y,n)){
		ans[paper[x][y]+1] += 1;
		return;
	}

	int tmp = n/3;

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			solve(x + i*tmp, y + j*tmp,tmp);
		}
	}
}
int N;

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&paper[i][j]);
		}
	}

	solve(0,0,N);

	for(int i = 0 ; i < 3 ; i++)
		printf("%d\n",ans[i]);

	return 0;
}
/* version 2
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int paper[2188][2188];
int ans[3];

void go(int x, int y, int len){
  if(len == 1){
    ans[paper[x][y] + 1]++;
    return;
  }

  int val = paper[x][y];
  bool check = true;
  for(int i = x ; i < x + len ; i++){
    for(int j = y ; j < y + len ; j++){
      if(paper[i][j] != val){
        check = false;
        break;
      }
    }
  }

  if(check){
    ans[val+1]++;
  }
  else{
    for(int i = x ; i < x + len ; i += len/3){
      for(int j = y ; j < y + len ; j += len/3){
        go(i,j,len/3);
      }
    }
  }
  return;
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i  < n ; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%d",&paper[i][j]);
    }
  }

  go(0,0,n);
  printf("%d\n%d\n%d\n",ans[0],ans[1],ans[2]);
  return 0;
}
*/
