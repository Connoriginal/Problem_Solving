#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<string> vec;

bool cmp(const string &u, const string &v){
	if(u.size() < v.size())
		return true;
	else if(u.size() > v.size())
		return false;
	else{
		if(u < v)
			return true;
		else
			return false;
	}
}
int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(),vec.end(),cmp);
	

	string pre = vec[0];
	cout << pre << "\n";
	for(string x : vec){
		if(x == pre)
			continue;
		cout << x << "\n";
		pre = x;
	}
	return 0;
}