#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

string str;
int main(void){
	cin >> str;

	int sum = 0;
	for(int i = 0 ; i < str.size() ; i++){
		sum += str[i] - '0';
	}


	sort(str.begin(),str.end());

	if(str[0] == '0' && sum % 3 == 0){
		reverse(str.begin(),str.end());
		cout << str << '\n';
	}
	else{
		printf("-1\n");
	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  string str;
  cin >> str;

  string ans;

  int sum = 0;
  bool zero = false;
  for(int i = 0 ; i < str.size() ; i++){
    int temp = str[i] - '0';
    if(temp == 0) zero = true;
    sum += temp;
    ans += str[i];
  }

  if(sum % 3 != 0 || !zero){
    printf("-1\n");
    return 0;
  }

  sort(ans.begin(),ans.end(),greater<char>());

  cout << ans <<'\n';
  return 0;
}
*/
