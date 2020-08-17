#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int arr[13];

void solve(vector<int> vec , int i, int max){
	if(vec.size() == 6){
		for(int i = 0 ; i < 6 ; i++)
			printf("%d ",vec[i]);
		printf("\n");
		return;
	}
	if(i >= max) return;
	
	vec.push_back(arr[i]);
	solve(vec,i+1,max);
	vec.pop_back();
	solve(vec,i+1,max);
	return;
}

int main() {
	while(true){
		int n;
		scanf("%d",&n);
		if(n==0) break;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&arr[i]);
		}
		vector<int> ans;
		solve(ans,0,n);
		printf("\n");
	}
    return 0;
}