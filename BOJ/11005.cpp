#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long cmd;
int b;
string ans = "";

int main(void){
	scanf("%lld %d",&cmd,&b);
	while(cmd > 0){
		int tmp = cmd % b;
		cmd /= b;
		if(tmp < 10)
			ans += char(tmp + '0');
		else
			ans += char(tmp - 10 + 'A');

	}
	reverse(ans.begin(),ans.end());
	cout << ans << '\n';
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char arr[36] = {'0','1','2','3','4','5','6','7','8','9','A',
'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
'Q','R','S','T','U','V','W','X','Y','Z'};


int main(void){
  int a,b;
  scanf("%d %d",&a,&b);

  vector<char> vec;

  while(a != 0){
    vec.push_back(a%b);
    a /= b;
  }

  while(!vec.empty()){
    printf("%c",arr[vec.back()]);
    vec.pop_back();
  }
  printf("\n");
}
*/
