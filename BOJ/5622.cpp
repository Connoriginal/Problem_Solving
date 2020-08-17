#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char str[16];
int tim[10] = {11,2,3,4,5,6,7,8,9,10};

int main(void){
	scanf("%s",str);
	int len = strlen(str);
	int cnt = 0;
	
	for(int i = 0 ; i < len ; i++){
		char tmp = str[i];
		if('A' <= tmp && tmp <= 'C')
			cnt += tim[2];
		else if('D' <= tmp && tmp <= 'F')
			cnt += tim[3];
		else if('G' <= tmp && tmp <= 'I')
			cnt += tim[4];
		else if('J' <= tmp && tmp <= 'L')
			cnt += tim[5];
		else if('M' <= tmp && tmp <= 'O')
			cnt += tim[6];
		else if('P' <= tmp && tmp <= 'S')
			cnt += tim[7];
		else if('T' <= tmp && tmp <= 'V')
			cnt += tim[8];
		else if('W' <= tmp && tmp <= 'Z')
			cnt += tim[9];
	}
	printf("%d\n",cnt);
	return 0;
}

