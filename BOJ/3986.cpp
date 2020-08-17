#include <cstdio> //scanf, printf
#include <cstring> // strlen() 


using namespace std;

int n;
int result = 0;
char stk[1000150];
char str[1000150];
int sp;

int main(void) {

	scanf("%d", &n);
	
	while(n--){
		sp=0;
		scanf("%s", str);
		int len = strlen(str);
		for(int j = 0 ; j <len ; j++){
			if(sp==0|| stk[sp-1] != str[j])
				stk[sp++] =str[j];
			else
				sp-=1;
		}
		
		if(sp==0)
			result+=1;
		
	}
	
	printf("%d\n",result);
	return 0;
}