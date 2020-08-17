#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <string>


using namespace std;

string cmd;

int main(void) {
	while(getline(cin,cmd)){
		int alp_high = 0, alp_low = 0, digit = 0, sp = 0;
		for(char x: cmd){
			if(x == ' ')
				sp++;
			else if(x >= '0' && x <= '9')
				digit++;
			else if(x >= 'a' && x <='z')
				alp_low++;
			else if(x >= 'A' && x <='Z')
				alp_high++;
		}
		printf("%d %d %d %d\n",alp_low,alp_high,digit,sp);
	}
	return 0;
}