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
	int cnt = 1;
	while(true){
		int r,w,l;
		scanf("%d",&r);
		if(r==0) break;
		scanf("%d %d",&w,&l);
		
		int len = w*w + l*l;
		r = 4*r*r;
		
		if(r >= len)
			printf("Pizza %d fits on the table.\n",cnt++);
		else
			printf("Pizza %d does not fit on the table.\n",cnt++);
		
	}
	return 0;
}

