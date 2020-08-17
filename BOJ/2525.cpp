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
	int hour,min,add;
	scanf("%d %d %d",&hour,&min,&add);
	min += add;
	while(min >= 60){
		min -= 60;
		hour++;
		if(hour ==24)
			hour = 0;
	}
	printf("%d %d\n",hour,min);
	return 0;
}

