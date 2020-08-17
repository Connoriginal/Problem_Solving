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

int gcd(int a,int b){
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main(void){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int child = a * d + b * c, par = b*d;
	int g = gcd(child,par);
	printf("%d %d\n",child/g,par/g);
	return 0;
}

