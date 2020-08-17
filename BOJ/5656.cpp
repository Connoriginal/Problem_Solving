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
		int a,b;
		string tmp;
		cin >> a >> tmp >> b;
		if(tmp == "E") break;
		
		bool result;
		
		if(tmp[0] == '!') result = (a != b);
		else if(tmp[0] == '=') result = (a==b);
		else if(tmp[0] == '>'){
			if(tmp[1] == '=') result = (a>=b);
			else result = (a>b);
		}
		else if(tmp[0] == '<'){
			if(tmp[1] == '=') result = (a <= b);
			else result = (a<b);
		}
		
		
		printf("Case %d: %s\n",cnt++,result ? "true" : "false");
	}
	return 0;
}

