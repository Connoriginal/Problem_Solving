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

int N;
vector<string> vec;

bool cmp(const string &u, const string &v){
	if(u.size() == v.size())
		return u < v;
	return u.size() < v.size();
}

int main(void){
	scanf("%d",&N);
	while(N--){
		queue<char> que;
		string tmp;
		cin >> tmp;
		
		for(int i = 0 ; i < tmp.size() ; i++){
			char c = tmp[i];
			if('0' <= c && c <= '9'){
				que.push(c);
			}
			if('a' <= c && c <= 'z' || i == tmp.size()-1){
				if(!que.empty()){
					string str = "";
					while(que.front() == '0' && que.size() > 1){
						que.pop();
					}
					while(!que.empty()){
						str += que.front();
						que.pop();
					}
					
					vec.push_back(str);
				}
			}
		}
	}
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i = 0 ; i < vec.size() ; i++)
		cout << vec[i] << '\n';
	return 0;
}

