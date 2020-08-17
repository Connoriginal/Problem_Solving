#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Participant{
  int name,score,num,time;
};

bool cmp(const Participant &u, const Participant &v){
  if(u.score == v.score){
    if(u.num == v.num) return u.time < v.time;
    return u.num < v.num;
  }
  return u.score > v.score;
}

int main(void){
  int n;
  scanf("%d",&n);

  vector<Participant> vec(n);
  for(int i = 1 ; i <= n ; i++){
    vec[i-1].name = i;
    scanf("%d %d %d",&vec[i-1].score,&vec[i-1].num,&vec[i-1].time);
  }

  sort(vec.begin(),vec.end(),cmp);

  printf("%d\n",vec[0].name);
  return 0;
}
