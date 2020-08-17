#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char board[5][16];

int main(void){
	memset(board,'\0',sizeof(board));
	int len = 0;
	for(int i = 0 ; i < 5 ; i++){
		scanf("%s",board[i]);
		int tmp = strlen(board[i]);
		len = max(len,tmp);
	}
	
	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < 5 ; j++){
			if(board[j][i] != '\0'){
				printf("%c",board[j][i]);
			}
		}
	}
	printf("\n");
	return 0;
}