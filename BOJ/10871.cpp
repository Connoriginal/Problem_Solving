#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(void){
	int N,X;
	scanf("%d %d",&N,&X);
	for(int i = 0 ; i < N ; i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp < X)
			printf("%d ",tmp);
	}
	printf("\n");
	return 0;
}