#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct Meeting{
  int start,end;
};

bool cmp(const Meeting &u, const Meeting &v){
  if(u.end == v.end){
    return u.start < v.start;
  }
  else{
    return u.end < v.end;
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  vector<Meeting> a(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d %d",&a[i].start,&a[i].end);
  }

  sort(a.begin(),a.end(),cmp);

  int pos = 0;
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    if(pos <= a[i].start){
      pos = a[i].end;
      ans++;
    }
  }

  printf("%d\n",ans);
  return 0;
}
