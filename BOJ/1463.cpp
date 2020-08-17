//bottom up
#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

int cmd;
int d[1000005];

int main(void){
	scanf("%d",&cmd);	
	d[1] = 0;
	for(int i = 2 ; i < cmd + 1 ; i++){
		d[i] = d[i-1] + 1;
		if(i % 2 == 0 && d[i] > d[i/2] + 1)
			d[i] = d[i/2] + 1;
		if(i % 3 == 0 && d[i] > d[i/3] + 1)
			d[i] = d[i/3] + 1;
	}
	printf("%d\n",d[cmd]);
	return 0;
}
//top down
/*
#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

int cmd;
int d[1000005];

int dmp(int x){
	if(x == 1) return 0;
	if(d[x] > 0) return d[x];
	
	d[x] = dmp(x-1) + 1;
	
	if(x % 2 == 0){
		int temp = dmp(x/2) + 1;
		if(temp < d[x]) d[x] = temp;
	}
	
	if(x % 3 == 0){
		int temp = dmp(x/3) + 1;
		if(temp < d[x]) d[x] = temp;
	}
	return d[x];
}

int main(void){
	scanf("%d",&cmd);	
	printf("%d\n",dmp(cmd));
	return 0;
}
*/