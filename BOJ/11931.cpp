#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	priority_queue<int> que;
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		que.push(tmp);
	}
	
	while(!que.empty()){
		printf("%d\n",que.top());
		que.pop();
	}
	return 0;
}