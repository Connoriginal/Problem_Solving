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
	int wid,hig;
	scanf("%d %d",&hig,&wid);
	if(hig == 1){
		printf("%d\n",1);
		return 0;
	}
	else if(hig == 2){
		printf("%d\n",min(4,(wid+1)/2));
		return 0;
	}
	else{
		if(wid < 7){
			printf("%d\n",min(4,wid));
			return 0;
		}
		else{
			printf("%d\n",wid-2);
			return 0;
		}
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
  int n,m;
  scanf("%d %d",&n,&m);
  int ans = 1;

  if(n == 1){
    ans = 1;
  }
  else if(n < 3){
    ans = min(4,(m+1)/2);
  }
  else{
    if(m <= 6){
      ans = min(4,m);
    }
    else{
      ans = 4 + (m-6);
    }
  }
  printf("%d\n",ans);
  return 0;
}
*/
