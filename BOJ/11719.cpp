/*
//c++식
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string str;

int main(void) {
	while(getline(cin,str))
		cout << str << '\n';
	return 0;
}

// c 식
#include <cstdio>


using namespace std;

char str[105];

int main(void) {
	while(fgets(str,100,stdin))
		printf("%s",str);
	return 0;
}

// c 식2
#include <cstdio>


using namespace std;

char c;

int main(void) {
	while((c = getchar()) && c != EOF)
		printf("%c",c);
	return 0;
}
*/