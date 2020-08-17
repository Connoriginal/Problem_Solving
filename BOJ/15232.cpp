#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int h,w;
	scanf("%d %d",&h,&w);
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

