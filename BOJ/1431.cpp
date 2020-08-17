#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Cereal{
	char name[51];
};

bool cmp(const Cereal &u, const Cereal &v){
	int len_u = strlen(u.name);
	int len_v = strlen(v.name);
	if(len_u == len_v){
		int ulen = 0, vlen = 0;
		for(int i = 0 ; i < len_u ; i++){
			if(u.name[i] >= 48 && u.name[i] <= 57) ulen += u.name[i] - 48;
			if(v.name[i] >= 48 && v.name[i] <= 57) vlen += v.name[i] - 48;
			
		}
		if(ulen == vlen){
			return strcmp(u.name,v.name) < 0;
		}
		return ulen < vlen;
	}
	return len_u < len_v;
}

int main(void){
	int N;
	scanf("%d",&N);
	Cereal cer[1001];
	for(int i = 0 ; i < N ; i++){
		scanf("%s",cer[i].name);
	}
	
	sort(cer,cer+N,cmp);
	
	for(int i = 0 ; i < N ; i++)
		printf("%s\n",cer[i].name);
	return 0;
}