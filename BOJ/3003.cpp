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
int correct[] = {1,1,2,2,2,8};
int inp[6];
int ans[6];

int main(void){
	for(int i = 0 ; i < 6 ; i++){
		scanf("%d",&inp[i]);
	}
	
	for(int i = 0 ; i < 6 ; i++){
		int tmp = correct[i] - inp[i];
		ans[i] = tmp;
	}
	
	for(int i = 0 ; i < 6 ; i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

