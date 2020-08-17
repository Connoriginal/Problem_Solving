#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>


using namespace std;


int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  vector<bool> check(1000000001,false);
  queue<int> que;

  for(int i = 0 ; i < n ; i++){
    int temp;
    scanf("%d",&temp);
    if(check[temp] == false){
      que.push(temp);
      check[temp] = true;
    }

    if(que.size() > k){
      check[que.front()] = false;
      que.pop();
    }
  }

  printf("%lu\n",que.size());
  vector<int> ans;
  while(!que.empty()){
    ans.push_back(que.front());
    que.pop();
  }

  while(!ans.empty()){
    printf("%d ",ans.back());
    ans.pop_back();
  }

  printf("\n");
  return 0;
}
