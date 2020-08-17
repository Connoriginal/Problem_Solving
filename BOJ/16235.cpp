#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int n,m,k;
int ans = 0;
int a[12][12],b[12][12];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(void){
  scanf("%d %d %d",&n,&m,&k);
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      scanf("%d",&a[i][j]);
      b[i][j] = 5;
    }
  }

  deque<int> dq[12][12];

  for(int i = 0 ; i < m ; i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    dq[x][y].push_back(z);
    ans++;
  }

  while(k--){

    //spring && summer
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        for(int k = 0 ; k < dq[i][j].size() ; k++){
          int cur = dq[i][j][k];
          if(cur > b[i][j]){

            for(int r = dq[i][j].size()-1 ; r >= k ; r--){
              b[i][j] += dq[i][j][r]/2;
              dq[i][j].pop_back();
              ans--;
            }
            break;

          }else{

            b[i][j] -= cur;
            dq[i][j][k]++;

          }
        }
      }
    }

    //fall && winter
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        for(int k = 0 ; k < dq[i][j].size() ; k++){
          if(dq[i][j][k]%5 == 0){

            for(int r = 0 ; r < 8 ; r++){
              int nx = i + dx[r];
              int ny = j + dy[r];
              if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                dq[nx][ny].push_front(1);
                ans++;
              }
            }

          }
        }
        b[i][j] += a[i][j];
      }
    }
  }

  printf("%d\n",ans);
  return 0;
}
