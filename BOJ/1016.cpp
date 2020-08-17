#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

long long in_min;
long long in_max;
bool check[1000001];

int main(void){
	scanf("%lld %lld",&in_min,&in_max);
	
	for(long long i = 2 ; i*i <= in_max ; i++){
		long long tmp = i*i;
		long long range_min = in_min / tmp;
		long long range_max = in_max/tmp;
		for(long long range = range_min ; range <= range_max ; range++){
			if(in_min <= tmp * range && tmp * range <= in_max)
				check[(tmp*range) - in_min] = true;
		}
	}
	
	int cnt = 0;
	for(int i = 0 ; i <= (in_max - in_min) ; i++){
		cnt += (check[i] == false)? 1 : 0;
	}
	
	printf("%d\n",cnt);
	return 0;
}