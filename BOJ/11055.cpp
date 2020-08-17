#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

long long cmd;
int b;
string ans = "";

int main(void){
	scanf("%lld %d",&cmd,&b);
	while(cmd > 0){
		int tmp = cmd % b;
		cmd /= b;
		if(tmp < 10)
			ans += char(tmp + '0');
		else
			ans += char(tmp - 10 + 'A');
		
	}
	reverse(ans.begin(),ans.end());
	cout << ans << '\n';
	return 0;
}


	