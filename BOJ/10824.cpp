#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <string>


using namespace std;

int A,B,C,D;
string str1, str2;

int main(void) {
	scanf("%d %d %d %d",&A,&B,&C,&D);
	
	string str1 = to_string(A) + to_string(B);
	string str2 = to_string(C) + to_string(D);
	
	long long val1 = stoll(str1);
	long long val2 = stoll(str2);
	
	printf("%llu\n",val1 + val2);
	return 0;
}
/*
#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <string>


using namespace std;

long long ans = 0;
string str, tmp;

int main(void) {
	for(int i = 0 ; i < 4; i++){
		if(i % 2 == 0){
			cin >> str;
		}
		else{
			cin >> tmp;
			str.append(tmp);
			ans += stoll(str);
		}
	}
	printf("%llu\n",ans);
	return 0;
}
*/