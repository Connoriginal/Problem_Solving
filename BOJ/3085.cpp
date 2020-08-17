#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char arr[51][51];
int n;

int check(void){
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int row = 1;
    for(int j = 0 ; j < n-1 ; j++){
      while(arr[i][j] == arr[i][j+1] && j < n-1){
        row++;
        j++;
      }
      if(row > 1 && row > ans) ans = row;
      row = 1;
    }

    int col = 1;
    for(int j = 0 ; j < n-1 ; j++){
      while(arr[j][i] == arr[j+1][i] && j < n-1){
        col++;
        j++;
      }
      if(col > 1 && col > ans) ans = col;
      col = 1;
    }
  }
  return ans;
}

int main(void){
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%s",arr[i]);
  }

  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(j+1 < n){
        swap(arr[i][j],arr[i][j+1]);
        int temp = check();
        ans = (temp > ans) ? temp : ans;
        swap(arr[i][j],arr[i][j+1]);
      }
      if(i+1 < n){
        swap(arr[i][j],arr[i+1][j]);
        int temp = check();
        ans = (temp > ans) ? temp : ans;
        swap(arr[i][j],arr[i+1][j]);
      }
    }
  }


  printf("%d\n",ans);
  return 0;
}
