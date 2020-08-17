#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n;
queue <int> que;

int main(void){
  scanf("%d",&n);
  for(int i = 1; i <= n ; i++) que.push(i);

  while(que.size() != 1){
    que.pop();
    que.push(que.front());
    que.pop();
  }

  printf("%d\n",que.front());
  return 0;
}
