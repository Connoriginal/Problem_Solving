#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Member{
	int age;
	char name[101];
};

bool cmp(const Member &u,const Member &v){
	if(u.age < v.age)
		return true;
	else
		return false;
}
int N;

int main(void){
	scanf("%d",&N);
	vector<Member> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d %s",&vec[i].age,vec[i].name);

	stable_sort(vec.begin(),vec.end(),cmp);

	for(int i = 0 ; i < N ; i++)
		printf("%d %s\n",vec[i].age,vec[i].name);

	return 0;
}
/* join 추가
struct Member{
	int age;
	char name[101];
	int join;
};

bool cmp(const Member &u,const Member &v){
	if(u.age < v.age)
		return true;
	else if(u.age == v.age)
		return u.join < v.join;
	else
		return false;
}
int N;

int main(void){
	scanf("%d",&N);
	vector<Member> vec(N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %s",&vec[i].age,vec[i].name);
		vec[i].join = i;
	}

	stable_sort(vec.begin(),vec.end(),cmp);

	for(int i = 0 ; i < N ; i++)
		printf("%d %s\n",vec[i].age,vec[i].name);

	return 0;
}
*/

/*join + operator overloading 포함
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
  int age, turn;
  string name;
  bool operator < (const Info &v) const{
    if(age < v.age) return true;
    else if(age == v.age) return turn < v.turn;
    else return false;
  }
};

int main(void){
  int n;
  scanf("%d",&n);

  vector<Info> vec(n);

  for(int i = 0 ; i < n ; i++){
    cin >> vec[i].age >> vec[i].name;
    vec[i].turn = i+1;
  }

  sort(vec.begin(),vec.end());

  for(int i = 0 ; i < n ; i++){
    cout << vec[i].age << " " << vec[i].name << '\n';
  }
  return 0;
}
*/
