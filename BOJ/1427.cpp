#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int N;
	scanf("%d",&N);
	priority_queue<int> que;
	while(N>0){
		que.push(N%10);
		N /= 10;
	}
	
	while(!que.empty()){
		printf("%d",que.top());
		que.pop();
	}
	printf("\n");
	return 0;
}

