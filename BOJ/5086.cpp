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
	while(true){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a == 0 && b == 0) break;
		
		bool neither = true;
		
		if(b > a){
			if(b % a == 0){
				printf("factor\n");
				neither = false;
			}
		}
		else{
			if(a % b == 0){
				printf("multiple\n");
				neither = false;
			}
		}
		
		if(neither)
			printf("neither\n");
	}
	return 0;
}

