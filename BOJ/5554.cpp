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
	int sec = 0, min = 0;
	for(int i = 0 ; i < 4 ; i++){
		int tmp;
		scanf("%d",&tmp);
		sec += tmp;
	}
	
	while(sec >= 60){
		sec -= 60;
		min++;
	}
	
	printf("%d\n%d\n",min,sec);
	return 0;
}

