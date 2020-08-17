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

string pl(string a, string b){
	int sum = 0;
	string ans;
	while(!a.empty() || !b.empty() || sum > 0){
		if(!a.empty()){
			sum += a.back() - '0';
			a.pop_back();
		}
		if(!b.empty()){
			sum += b.back() - '0';
			b.pop_back();
		}
		
		ans.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(void){
	string a,b;
	cin >> a >> b;
	
	cout << pl(a,b) << '\n';
	return 0;
}

