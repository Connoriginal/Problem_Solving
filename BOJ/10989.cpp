#include <iostream>
#include <cstdio>


using namespace std;

int arr[10001];

int main(void){
  int n;
  scanf("%d",&n);

  while(n--){
    int tmp;
    scanf("%d",&tmp);
    arr[tmp]++;
  }

  for(int i = 1 ; i <= 10000 ; i++){
    if(arr[i] == 0) continue;
    while(arr[i] > 0){
      printf("%d\n",i);
      arr[i]--;
    }
  }
  return 0;
}
