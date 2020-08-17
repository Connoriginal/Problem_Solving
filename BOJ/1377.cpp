#include <iostream>
#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;



int N;

int main(void){
	scanf("%d",&N);
	vector<pair<int,int>> vec(N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&vec[i].first);
		vec[i].second = i;
	}
	
	sort(vec.begin(),vec.end());
	
	int ans = 0;
	for(int i = 0 ; i < N ; i++){
		if(vec[i].second - i > ans){
			ans = vec[i].second - i;
		}	
	}
	
	printf("%d\n",ans+1);
	return 0;
}