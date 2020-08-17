#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

string cmd;
string eight[8] = {"000","001","010","011","100","101","110","111"};
string init_eight[] ={"000","1","10","11","100","101","110","111"};

int main(void){
	cin >> cmd;
	int len = cmd.size();
	
	if(cmd == "0"){
		printf("0\n");
		return 0;
	}
	
	for(int i = 0 ; i < len ; i++){
		int tmp = cmd[i] - '0';
		if(i==0)
			cout << init_eight[tmp];
		else
			cout << eight[tmp];
	}
	
	printf("\n");
	return 0;
}

