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
	int h,m;
	scanf("%d %d",&h,&m);
	
	if(m < 45){
		m = m + 15;
		if(h == 0)
			h = 23;
		else
			h--;
	}
	else
		m -= 45;
	
	printf("%d %d\n",h,m);
	return 0;
}

