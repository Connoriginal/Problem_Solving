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
	int burger = 3000, drink = 3000;
	for(int i = 0 ; i < 3 ; i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp < burger) burger = tmp; 
	}
	
	for(int i = 0 ; i < 2 ; i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp < drink) drink = tmp;
	}
	
	printf("%d\n",burger + drink - 50);
	return 0;
}

