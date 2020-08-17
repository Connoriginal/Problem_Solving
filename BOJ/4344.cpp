#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int num;
		scanf("%d",&num);
		vector<float> score(num);
		float av = 0.0;
		for(int i = 0 ; i < num ; i++){
			scanf("%f",&score[i]);
			av += score[i];
		}
		av /= num;
		float ans = 0.0;
		
		for(int i = 0 ; i < num ; i++){
			if(score[i] > av)
				ans += 1.0;
		}
		
		printf("%.3f%%\n",ans/num * 100);
	}
	return 0;
}