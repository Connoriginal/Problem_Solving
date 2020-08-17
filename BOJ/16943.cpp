#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char a[11];
int b;

int main(void){
  //입력
  scanf("%s",a);
  vector<int> vec;

  int len = strlen(a);
  for(int i = 0 ; i < len ; i++) vec.push_back(a[i] - '0');

  scanf("%d",&b);

  //풀이
  sort(vec.begin(),vec.end(),greater<int>());

  do{
    if(vec[0] == 0) break;

    int ans = 0;
    for(int i = 0 ; i < vec.size() ; i++){
      ans *= 10;
      ans += vec[i];
    }
    if(ans <= b){
      printf("%d\n",ans);
      return 0;
    }
  }while(prev_permutation(vec.begin(),vec.end()));

  printf("-1\n");
  return 0;
}
