#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>

using namespace std;

int N,K;
queue<int> que;

int main(void) {
	scanf("%d %d",&N,&K);
	for(int i = 1 ; i < N + 1; i++)
		que.push(i);
	
	printf("<");	
	
	while(que.size() > 1){
		for(int i = 0 ; i < K - 1 ; i++){
			que.push(que.front());
			que.pop();
		}
		printf("%d, ",que.front());
		que.pop();
	}
	
	printf("%d>\n",que.front());
	
	return 0;
}