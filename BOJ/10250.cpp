#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int h , w, n;
		scanf("%d %d %d",&h,&w,&n);
		int x = n / h + 1;
		int y = n % h;
		if(y == 0){
			y = h;
			x--;
		}
		if(x < 10)
			printf("%d0%d\n",y,x);
		else
			printf("%d%d\n",y,x);
	}
	return 0;
}

