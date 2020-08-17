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
	int t;
	scanf("%d",&t);
	int a = 0,b = 0;
	while(t--){
		int u,v;
		scanf("%d %d",&u,&v);
		if(u > v)
			a++;
		else if(u < v)
			b++;
	}
	printf("%d %d\n",a,b);
	return 0;
}

