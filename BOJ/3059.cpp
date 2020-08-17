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

bool check[26];

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(check,false,sizeof(check));
		string str;
		cin >> str;
		for(char c : str){
			check[c-'A'] = true;
		}
		
		int ans = 0;
		for(int i = 0 ; i < 26 ; i++){
			if(check[i] == false){
				ans += i + 'A';
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

