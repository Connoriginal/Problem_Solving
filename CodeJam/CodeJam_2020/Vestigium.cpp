#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int row[101][101];
int column[101][101];

int main(void){
  scanf("%d",&T);
  for(int test_case = 1 ; test_case <= T ; test_case++){
    int n;
    scanf("%d",&n);

    int k = 0, r = 0 , c = 0;

    memset(row,0,sizeof(row));
    memset(column,0,sizeof(column));

    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        int temp;
        scanf("%d",&temp);

        if(i == j){
          k += temp;
        }

        row[i][temp]++;
        column[j][temp]++;
      }
    }

    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j <= n ; j++){
        if(row[i][j] > 1){
          r++;
          break;
        }
      }
    }

    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j <= n ; j++){
        if(column[i][j] > 1){
          c++;
          break;
        }
      }
    }
    printf("Case #%d: %d %d %d\n", test_case,k,r,c);
  }
  return 0;
}
