#include <iostream>
#include <queue>

using namespace std;


int n;
int map[21][21];
int check[21][21];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int shark_size = 2, eat_num = 0;
int shark_x,shark_y;
int ans = 0;

void go(void){
  fill(&check[0][0],&check[20][20],-1);

  //bfs
  queue<pair<int,int> > que;
  check[shark_x][shark_y] = 0;
  que.push(make_pair(shark_x,shark_y));

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int k = 0 ; k < 4 ; k++){
      int nx = x + dx[k], ny = y + dy[k];
      if(0 <= nx && nx < n && 0 <= ny && ny < n){
        if(map[nx][ny] <= shark_size){
          if(check[nx][ny] == -1 || check[nx][ny] > check[x][y] + 1){
            check[nx][ny] = check[x][y] + 1;
            que.push(make_pair(nx,ny));
          }
        }
      }
    }
  }

  bool flag = false;
  int len = 402;
  int x,y;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(map[i][j] && map[i][j] < shark_size){
        int tmp = check[i][j];

        if(tmp == -1) continue;

        flag = true;
        if(tmp < len){
          x = i; y = j;
          len = tmp;
        }else if(tmp == len && i < x){
            x = i; y = j;
        }
      }
    }
  }

  if(!flag) return;

  ans += len;
  map[x][y] = 0;
  shark_x = x; shark_y = y;

  if(++eat_num >= shark_size){
    eat_num = 0;
    shark_size++;
  }
  go();
  return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        cin >> map[i][j];
        if(map[i][j] == 9){
          shark_x = i; shark_y = j;
          map[i][j] = 0;
        }
      }
    }

    go();

    cout << ans << '\n';
    return 0;
}
