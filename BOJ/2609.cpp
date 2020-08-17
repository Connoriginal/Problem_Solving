#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int gcd(int a, int b){
	while(b != 0){
		int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}
/*
int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}
*/

int main(void){
	int a, b;
	scanf("%d %d",&a,&b);
	int g = gcd(a,b);
	printf("%d\n%d\n",g,a*b/g);

	return 0;
}
