#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i++){
		printf("Class %d\n",i);
		int num;
		scanf("%d",&num);
		vector<int> vec(num);
		for(int i = 0 ; i < num ; i++)
			scanf("%d",&vec[i]);
		
		sort(vec.begin(),vec.end());
		int large = 0;
		for(int i = 0 ; i < num -1 ; i++){
			if(vec[i+1] - vec[i] > large)
				large = vec[i+1] - vec[i];
		}
		printf("Max %d, Min %d, Largest gap %d\n",vec.back(),vec.front(),large);
	}
	
	return 0;
}

