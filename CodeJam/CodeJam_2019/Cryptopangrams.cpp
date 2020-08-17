#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>  

//'A' == 65
int T, L;
long long int N, temp;
long long int prime[1000], ansint[1000];
char ans[1000];

int main(void){
	scanf("%d",&T);
	for(int i = 1 ; i < T + 1 ; i++){
		scanf("%lld %d",&N,&L);
		
		long long val;
		for(int j = 0 ; j < L ; j++){
			scanf("%lld",&temp);
			
			
			if(j == 0){
				for(int k = 3 ; k < temp / 2 ; k+=2){
					if(temp % k == 0){
						val = k;
						prime[0] = temp / val;
						ansint[0] = temp / val;
					}
				}
			}
			
			else if(j == 1){
				if(temp % prime[0] == 0){
					long long tmp = prime[0];
					prime[0] = val;
					ansint[0] = val;
					val = tmp;
				}
				prime[j] = val;
				ansint[j] = val;
				val = temp / val;
			}
			
			else{
				prime[j] = val;
				ansint[j] = val;
				val = temp / val;
			}
		}
		
		sort(prime,prime+L);
		
		
		printf("Case #%d: %s\n",i,ans);
	}
	
	return 0;
}