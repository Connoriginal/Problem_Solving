#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,m;

int arr[100001],bef[100001],aft[100001];

bool check(void){
  for(int i = 1 ; i <= n ; i++){
    if(arr[i] != aft[i]) return false;
  }
  return true;
}

int main(void){
  scanf("%d %d",&n,&m);

  vector<vector<int> > vec(m);

  for(int i = 0 ; i < m ; i++){
    int k;
    scanf("%d",&k);
    for(int j = 0 ; j < k ; j++){
      int tmp;
      scanf("%d",&tmp);
      vec[i].push_back(tmp);
    }
  }

  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&arr[i]);
    bef[i] = arr[i];
    aft[i] = arr[i];
  }

  //시작 상태 만들기
  for(int i = m-1 ; i >= 0; i--){
    bool flag = false;
    for(int j = 0 ; j < vec[i].size() ; j++){
      int cur = vec[i][j];
      if(bef[cur] == 0){
        flag = true;
        break;
      }
    }

    if(flag){
      for(int j = 0 ; j < vec[i].size() ; j++){
        bef[vec[i][j]] = 0;
        aft[vec[i][j]] = 0;
      }
    }
  }

  //시작 상태에서 결과값 만들기
  for(int i = 0 ; i < m ; i++){
    bool flag = false;
    for(int j = 0 ; j < vec[i].size() ; j++){
      int cur = vec[i][j];
      if(aft[cur] == 1){
        flag = true;
        break;
      }
    }

    if(flag){
      for(int j = 0 ; j < vec[i].size() ; j++){
        aft[vec[i][j]] = 1;
      }
    }
  }


  if(!check()){
    printf("NO\n");
  }else{
    printf("YES\n");
    for(int i = 1 ; i <= n ; i++){
      printf("%d ",bef[i]);
    }
    printf("\n");
  }
  return 0;
}
