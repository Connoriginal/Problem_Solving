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


int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int e = 1, s = 1, m = 1;
	int ans;
	for(ans = 1 ; ; ans++){
		if(e == a && s == b && m == c)
			break;
		e++; s++; m++;
		if(e>15) e = 1;
		if(s>28) s = 1;
		if(m>19) m = 1;
	}

	printf("%d\n",ans);
	return 0;
}

/* version 2
#include <iostream>
#include <cstdio>


using namespace std;

int main() {
  int e,s,m;
  scanf("%d %d %d",&e,&s,&m);

  int ans = 1;
  int a = 1, b = 1 , c = 1;
  while(!(a==e && b == s && c == m)){
    ans++;a++;b++;c++;
    if(a > 15) a = 1;
    if(b > 28) b = 1;
    if(c > 19) c = 1;
  }
  printf("%d\n",ans);
  return 0;
}
*/
