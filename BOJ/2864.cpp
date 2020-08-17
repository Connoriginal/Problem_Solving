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
	string ans;
	int sum = 0;
	while(!a.empty() || !b.empty() || sum > 0){
		if(!a.empty()){
			sum += a.back() - '0';
			a.pop_back();
		}
		if(!b.empty()){
			sum += b.back() - '0';
			b.pop_back();
		}
		
		ans.push_back((sum%10) + '0');
		sum /= 10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(void){
	string a,b;
	cin >> a >> b;
	
	//최소
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] == '6') a[i] = '5';
	}
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i] == '6') b[i] = '5';
	}
	cout << pl(a,b) << " ";
	
	//최대
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] == '5') a[i] = '6';
	}
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i] == '5') b[i] = '6';
	}
	cout << pl(a,b) << '\n';
	
	return 0;
}

