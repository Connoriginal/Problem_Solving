#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void){
	vector<int> vec(3);
	for(int i = 0 ; i < 3 ; i++){
		scanf("%d",&vec[i]);
	}
	sort(vec.begin(),vec.end());
	printf("%d\n",vec[1]);
	return 0;
}