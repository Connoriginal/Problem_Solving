#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	priority_queue<pair<int,int>> score;
	for(int i = 1 ; i <= 8 ; i++){
		int tmp;
		scanf("%d",&tmp);
		score.push(make_pair(tmp,i));
	}
	
	priority_queue<int,vector<int>,greater<int>> que;
	int sum = 0;
	for(int i = 0 ; i < 5 ; i++){
		int num = score.top().first;
		que.push(score.top().second);
		score.pop();
		sum += num;
	}
	
	printf("%d\n",sum);
	for(int i = 0 ; i < 5 ; i++){
		printf("%d ",que.top());
		que.pop();
	}
	printf("\n");
	return 0;
}