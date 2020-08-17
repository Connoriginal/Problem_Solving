#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int t, N,M;
int ans;
queue<pair<int,int>> que;
vector<int> vec;

int main(void){
	scanf("%d",&t);
	while(t--){
		ans = 0;
		vec.clear();
		while(!que.empty()) que.pop();
		
		scanf("%d %d",&N,&M);
		for(int i = 0 ; i < N ; i++){
			int temp;
			scanf("%d",&temp);
			que.push(make_pair(temp,i));
			vec.push_back(temp);
		}
		
		sort(vec.begin(),vec.end());
		
		
		while(1){
			if(vec.back() == que.front().first){
				vec.pop_back();
				ans++;
				if(que.front().second == M) break;
			}
			else{
				que.push(que.front());
			}
			que.pop();
		}
		
		printf("%d\n",ans);
	}
	return 0;
}