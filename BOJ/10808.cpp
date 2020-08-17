#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <deque>

using namespace std;
int alp[26] = {0,};
char cmd[101];

int main(void) {
	scanf("%s",cmd);
	int len = strlen(cmd);
	for(int i = 0 ; i < len ; i++)
		alp[cmd[i] - 'a']++;
	
	for(int i = 0 ; i < 26; i++)
		printf("%d ",alp[i]);
	
	printf("\n");
	return 0;
}
/*
#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <string>

using namespace std;
string cmd;

int main(void) {
	cin >> cmd;
	for(char i = 'a' ; i <= 'z' ; i++)
		cout << count(cmd.begin(),cmd.end(),i) << ' ';
	printf("\n");
	return 0;
}
*/