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
	int cnt = 0;
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			char c;
			scanf(" %c",&c);
			if(c == 'F' && (i+j) % 2 == 0){
				cnt++;
			}
		}
	}
	
	printf("%d\n",cnt);
	return 0;
}

