#include <iostream>
#include <cstdio> 
#include <cstring> // strlen() 

using namespace std;

int t;
int sp = 0;
char list[100];
int main() {
	scanf("%d",&t);
	while(t--){
		sp = 0;
		scanf("%s",list);
		int len = strlen(list);
		
		for(int i = 0 ; i < len ; i++){
			if(list[i] == '(')
				sp++;
			else if(list[i] == ')'){
				sp--;
				if(sp < 0)
					break;
			}
		}
		
		if(sp == 0)
			printf("%s\n","YES");
		else
			printf("%s\n","NO");
		
	}
	
	return 0;
}