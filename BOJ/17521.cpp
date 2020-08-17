#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long w;
int graph[20];

int main(void){
  scanf("%d %lld",&n,&w);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&graph[i]);
  }

  long long stock = 0;

  bool increase = false;

  if( graph[2] > graph[1]){
    stock = w / graph[1];
    w = w - stock * graph[1];
    increase = true;
  }

  for(int i = 2 ; i < n ; i++){
    if(increase && graph[i+1] < graph[i]){
      w += stock * graph[i];
      stock = 0;
      increase = false;
    }
    else if(!increase && graph[i+1] > graph[i]){
      stock = w/graph[i];
      w -= stock * graph[i];
      increase = true;
    }
  }

  if(stock != 0){
    w += stock * graph[n];
  }

  printf("%lld\n",w);
}
