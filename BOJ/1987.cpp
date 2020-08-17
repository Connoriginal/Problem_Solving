#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool alp[27];
char map[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int R,C;

int solve(int x,int y){
	int ans = 0;
	for(int k = 0 ; k < 4 ; k++){
		int nx = x + dx[k]; int ny = y + dy[k];
		if(0 <= nx && nx < R && 0 <= ny && ny < C){
			char tmp = map[nx][ny];
			if(!alp[tmp-'A']){
				alp[tmp-'A'] = true;
				int next = solve(nx,ny);
				if(ans < next) ans = next;
				alp[tmp-'A'] = false;
			}
		}
	}
	
	return ans + 1;
}

int main() {
	scanf("%d %d",&R,&C);
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			scanf(" %c",&map[i][j]);
		}
	}
	
	alp[map[0][0] - 'A'] = true;
	printf("%d\n",solve(0,0));
    return 0;
}