#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

queue<int> que;
queue<int> ans;

int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 1; i <= N ; i++)
		que.push(i);
	
	while(que.size() != 1) {
		ans.push(que.front());
		que.pop();
		que.push(que.front());
		que.pop();
	}
	
	ans.push(que.front());
	
	while(!ans.empty()){
		printf("%d ",ans.front());
		ans.pop();
	}
	printf("\n");
	return 0;
}

