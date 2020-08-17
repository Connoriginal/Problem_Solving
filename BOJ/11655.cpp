#include <iostream>
#include <cstdio> 
#include <cstring> 


using namespace std;

char str[101];

int main(void) {
	scanf("%[^\n]",str);
	int len = strlen(str);
	for(int i = 0 ; i < len ; i++){
		if((str[i] >= 'a' && str[i] < 'a' + 13) || (str[i] >= 'A' && str[i] < 'A' + 13))
			str[i] += 13;
		else if((str[i] >='a' + 13 && str[i] <='z') || (str[i] >= 'A' + 13 && str[i] <= 'Z'))
			str[i] -= 13;
	}
	
	printf("%s\n",str);
	return 0;
}