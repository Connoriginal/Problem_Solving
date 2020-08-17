#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Team{
  int team_id, num, time, total;
  int score[101];
};

bool cmp(const Team &u, const Team &v){
  if(u.total == v.total){
    if(u.num == v.num){
      return u.time < v.time;
    }
    return u.num < v.num;
  }
  return u.total > v.total;
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,k,t,m;
    scanf("%d %d %d %d",&n,&k,&t,&m);

    vector<Team> vec(n+1);

    for(int time = 0 ; time < m ; time++){
      int i,j,s;
      scanf("%d %d %d",&i,&j,&s);
      vec[i].score[j] = max(vec[i].score[j],s);
      vec[i].num++;
      vec[i].time = time;
    }

    for(int i = 1 ; i <= n ; i++){
      vec[i].team_id = i;
      for(int j = 1 ; j <= k ; j++){
        vec[i].total += vec[i].score[j];
      }
    }
    sort(vec.begin()+1,vec.end(),cmp);

    for(int i = 1 ; i <= n ; i++){
      if(vec[i].team_id == t) printf("%d\n",i);
    }
  }
  return 0;
}
