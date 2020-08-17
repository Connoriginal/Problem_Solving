#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool cmp(const pair<int,int> &u,const pair<int,int> &v){
	if(u.second < v.second)
		return true;
	else if(u.second == v.second)
		return u.first < v.first;
	else
		return false;
}
int main(void){
	scanf("%d",&N);
	vector<pair<int,int>> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d %d",&vec[i].first,&vec[i].second);

	sort(vec.begin(),vec.end(),cmp);
	for(int i = 0 ; i < N ; i++)
		printf("%d %d\n",vec[i].first,vec[i].second);

	return 0;
}

/* struct, operator overloading 사용
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
  int x,y;
  bool operator < (const Point &v) const{
    if(y < v.y) return true;
    else if(y == v.y) return x < v.x;
    else return false;
  }
};

int main(void){
  int n;
  scanf("%d",&n);

  vector<Point> vec(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d %d",&vec[i].x,&vec[i].y);
  }

  sort(vec.begin(),vec.end());

  for(int i = 0 ; i < n ; i++){
    printf("%d %d\n", vec[i].x, vec[i].y);
  }
  return 0;
}
*/
