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
	vector<int> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&vec[i]);
	
	if(prev_permutation(vec.begin(),vec.end())){
		for(int i = 0 ; i < N ; i++)
			printf("%d ",vec[i]);
	}
	else
		printf("-1");
	printf("\n");
	return 0;
}

