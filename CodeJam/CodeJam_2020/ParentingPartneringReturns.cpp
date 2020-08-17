#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>


using namespace std;

struct Point{
  int start,end,index;

};

bool cmp(Point &u, Point &v){
  if(u.start < v.start){
    return true;
  }
  else if(u.start > v.start){
    return false;
  }
  else{
    if(u.end < v.end) return true;
  }
  return false;
}

int T;
char ans[1001];

int main(void){
  scanf("%d",&T);
  for(int test_case = 1 ; test_case <= T ; test_case++){
    memset(ans,'\0',sizeof(ans));
    int n;
    scanf("%d",&n);

    vector<Point> vec(n);
    stack<Point> cam;
    stack<Point> jam;



    for(int i = 0 ; i < n ; i++){
      scanf("%d %d",&vec[i].start,&vec[i].end);
      vec[i].index = i;
    }

    sort(vec.begin(),vec.end(),cmp);

    for(int i = 0 ; i < n ; i++){
      if(cam.empty()){
        cam.push(vec[i]);
        ans[vec[i].index] = 'C';
      }

      else{
        if(vec[i].start >= cam.top().end){
          cam.push(vec[i]);
          ans[vec[i].index] = 'C';
        }
        else{
          if(jam.empty()){
            jam.push(vec[i]);
            ans[vec[i].index] = 'J';
          }
          else{
            if(vec[i].start >= jam.top().end){
              jam.push(vec[i]);
              ans[vec[i].index] = 'J';
            }
            else{
              strcpy(ans,"IMPOSSIBLE");
              break;
            }
          }
        }
      }
    }
    printf("Case #%d: %s\n",test_case,ans);
  }
  return 0;
}
