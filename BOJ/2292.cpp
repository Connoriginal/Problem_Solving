#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	else if(n < 8){
		printf("2\n");
		return 0;
	}
	

	int sum = 7;
	int lay = 2;
	int last = 6;
	for(int i = 1 ; ; i++){
		if(sum >= n)
			break;
		
		sum += last + 6;
		last+=6;
		lay++;
	}
	printf("%d\n",lay);
	
	return 0;
}

