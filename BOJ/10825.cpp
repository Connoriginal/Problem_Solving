#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

struct Student{
	int kor,eng,math;
	char name[11];
};

bool cmp(const Student &u,const Student &v){
	if(u.kor > v.kor)
		return true;
	else if(u.kor == v.kor){
		if(u.eng == v.eng){
			if(u.math == v.math){
				int tmp = strcmp(u.name,v.name);
				if(tmp < 0)
					return true;
				return false;
			}
			return u.math > v.math;
		}
		return u.eng < v.eng;
	}
	else
		return false;
}
int N;

int main(void){
	scanf("%d",&N);
	vector<Student> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%s %d %d %d",vec[i].name,&vec[i].kor,&vec[i].eng,&vec[i].math);
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i = 0 ; i < N ; i++)
		printf("%s\n",vec[i].name);
	return 0;
}
/* tuple 사용 메모리 증가, 시간 증가
struct Student{
	int kor,eng,math;
	string name;
};

bool cmp(const Student &u,const Student &v){
	return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor,v.eng,-v.math,v.name);
}
int N;

int main(void){
	scanf("%d",&N);
	vector<Student> vec(N);
	for(int i = 0 ; i < N ; i++)
		cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i = 0 ; i < N ; i++)
		cout << vec[i].name << '\n';
	return 0;
}
*/
