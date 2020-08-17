#include <iostream>
#include <cstdio> 
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int N, K;

int main(void){
	scanf("%d %d",&N,&K);
	vector<long long> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%lld",&vec[i]);
	
	sort(vec.begin(),vec.end());
	
	printf("%lld\n",vec[K-1]);

	return 0;
}
/*nth_element 사용
int N, K;

int main(void){
	scanf("%d %d",&N,&K);
	vector<long long> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%lld",&vec[i]);
	
	nth_element(vec.begin(),vec.begin() + (K-1),vec.end());
	
	printf("%lld\n",vec[K-1]);

	return 0;
}
*/
