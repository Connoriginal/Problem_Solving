#include <cstdio>

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char day[][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int x, y;
int num;

int main(void){
	scanf("%d %d",&x,&y);	
	num = y;
	for(int i = 0 ; i < x - 1 ; i++) num += month[i];
	num = (num-1) % 7;
	printf("%s\n",day[num]);
	return 0;
}