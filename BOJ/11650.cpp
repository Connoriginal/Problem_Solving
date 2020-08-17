#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  vector<pair<int,int> > vec(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d %d",&vec[i].first,&vec[i].second);
  }

  sort(vec.begin(),vec.end());

  for(int i = 0 ; i < n ; i++){
    printf("%d %d\n",vec[i].first,vec[i].second);
  }
  return 0;
}

/* struct, cmp 사용
int N;

struct Point{
	int x, y;
};

bool cmp(const Point &u, const Point &v){
	if(u.x < v.x)
		return true;
	else if(u.x == v.x)
		return u.y < v.y;
	else
		return false;
}
int main(void){
	scanf("%d",&N);
	vector<Point> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d %d",&vec[i].x,&vec[i].y);

	sort(vec.begin(),vec.end(),cmp);

	for(int i = 0 ; i < N ; i++)
		printf("%d %d\n",vec[i].x,vec[i].y);

	return 0;
}
*/

/*operator 오버로딩 사용1
int N;

struct Point{
	int x, y;
	bool operator < (const Point &v) const{
		if(x < v.x)
			return true;
		else if(x == v.x)
			return y < v.y;
		else
			return false;
	}
};


int main(void){
	scanf("%d",&N);
	vector<Point> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d %d",&vec[i].x,&vec[i].y);

	sort(vec.begin(),vec.end());

	for(int i = 0 ; i < N ; i++)
		printf("%d %d\n",vec[i].x,vec[i].y);

	return 0;
}
*/

/* operator 오버로딩 사용2
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
  int x,y;
  bool operator < (const Point &v) const {
    if(x < v.x) return true;
    else if(x == v.x) return y < v.y;
    else return false;
  }
};


int main(void){
  int n;
  scanf("%d",&n);

  Point arr[n];

  for(int i = 0 ; i < n ; i++){
    scanf("%d %d",&arr[i].x,&arr[i].y);
  }

  sort(arr,arr + n);

  for(int i = 0 ; i < n ; i++){
    printf("%d %d\n",arr[i].x,arr[i].y);
  }

  return 0;
}
*/
