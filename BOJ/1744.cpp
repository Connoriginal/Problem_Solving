#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(void){
  int n;
  scanf("%d",&n);
  vector<int> a;
  vector<int> b;
  for(int i = 0 ; i < n ; i++){
    int temp;
    scanf("%d",&temp);
    if(temp > 0) a.push_back(temp);
    else b.push_back(temp);
  }

  sort(a.begin(),a.end(),greater<int>());
  sort(b.begin(),b.end());

  vector<int> c;

  a.push_back(1);
  for(int i = 0 ; i < a.size()-1 ; i++){
    if(a[i] != 1 && a[i+1] != 1){
      c.push_back(a[i]*a[i+1]);
      i++;
    }
    else{
      c.push_back(a[i]);
    }
  }

  b.push_back(1);
  for(int i = 0 ; i < b.size()-1 ; i++){
    if(a[i]*a[i+1] >= 0){
      c.push_back(b[i]*b[i+1]);
      i++;
    }
    else{
      c.push_back(b[i]);
    }
  }

  int ans = 0;
  for(int i = 0 ; i < c.size() ; i++){
    ans += c[i];
  }

  printf("%d\n",ans);
  return 0;
}

/*
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

vector<int> pl;
vector<int> mi;
int zero = 0;
int one = 0;
int N;

bool cmp(const int &u, const int &v){
	return u > v;
}
int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp == 0)
			zero++;
		else if(tmp == 1)
			one++;
		else if(tmp > 1)
			pl.push_back(tmp);
		else if(tmp < 0)
			mi.push_back(tmp);
	}

	sort(mi.begin(),mi.end());
	sort(pl.begin(),pl.end(),cmp);

	int ans = one;
	if(pl.size() % 2 == 0){
		for(int i = 1 ; i < pl.size() ; i+=2){
			ans += pl[i] * pl[i-1];
		}
	}
	else{
		for(int i = 1 ; i < pl.size() ; i+=2){
			ans += pl[i] * pl[i-1];
		}
		ans += pl[pl.size()-1];
	}

	if(mi.size() % 2 == 0){
		for(int i = 1 ; i < mi.size() ; i+=2){
			ans += mi[i] * mi[i-1];
		}
	}
	else{
		for(int i = 1 ; i < mi.size() ; i+=2){
			ans += mi[i] * mi[i-1];
		}
		if(zero == 0){
			ans += mi[mi.size() -1];
		}
	}
	printf("%d\n",ans);
	return 0;
}
*/
