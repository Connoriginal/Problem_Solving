#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){
	int N;
	scanf("%d",&N);
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i = 0 ; i < N ; i++){
		int tmp;
		scanf("%d",&tmp);
		pq.push(tmp);
	}

	int ans = 0;
	while(pq.size() != 1){
		int fir = pq.top(); pq.pop();
		int sec = pq.top(); pq.pop();
		ans += fir + sec;
		pq.push(fir + sec);
	}
	
	printf("%d\n",ans);
	return 0;
}