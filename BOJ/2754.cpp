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

float score[4][3] = {{4.3,4.0,3.7},{3.3,3.0,2.7},{2.3,2.0,1.7},{1.3,1.0,0.7}};

int main(void){
	char c;
	scanf("%c",&c);
	if(c == 'F'){
		printf("0.0\n");
		return 0;
	}
	int fir = c - 'A';
	
	scanf("%c",&c);
	
	int sec = (c == '+') ? 0 : (c == '0') ? 1 : 2;
	
	printf("%.1f\n",score[fir][sec]);
	return 0;
}

