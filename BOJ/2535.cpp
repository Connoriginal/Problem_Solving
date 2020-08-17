#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Participant{
  int country, student, grade;
};

bool cmp(const Participant &u, const Participant &v){
  return u.grade > v.grade;
}

int a[101];

int main(void){
  int n;
  scanf("%d",&n);

  vector<Participant> vec(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d %d %d",&vec[i].country,&vec[i].student,&vec[i].grade);
  }

  sort(vec.begin(),vec.end(),cmp);

  int cnt = 0, pt = 0;
  while(cnt < 3){
    if(a[vec[pt].country] < 2){
      printf("%d %d\n",vec[pt].country,vec[pt].student);
      a[vec[pt].country]++;
      cnt++;
    }
    pt++;
  }
  return 0;
}
