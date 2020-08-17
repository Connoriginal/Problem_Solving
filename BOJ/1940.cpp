#include <iostream>
#include <cstdio>

using namespace std;

int ing[15001];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&ing[i]);
  }

  int cnt = 0;
  for(int i = 0 ; i < n-1 ; i++){
    for(int j = i+1 ; j < n ; j++){
      if(ing[i] + ing[j] == m) cnt++;
    }
  }

  printf("%d\n",cnt);
}
