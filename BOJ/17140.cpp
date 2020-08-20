#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define pb push_back
#define mp make_pair

using namespace std;

int r,c,k;
int row = 2, col = 2;
int map[101][101];
int cnt[101];
int ans = 0;

void R_function(void){
  vector<int> col_num(row+1);
  int next_col = col;

  for(int i = 0 ; i <= row ; i++){
    fill(&cnt[0],&cnt[100],0);
    for(int j = 0 ; j <= col ; j++) cnt[map[i][j]]++;

    vector<pair<int, int> > vec;

    cnt[0] = 0;
    for(int j = 0 ; j <= col ; j++){
      int cur = map[i][j];
      if(cnt[cur]){
        vec.pb(mp(cnt[cur],cur));
        cnt[cur] = 0;
      }
    }

    sort(vec.begin(),vec.end());

    int pt = 0;
    for(int q = 0 ; q < vec.size() ; q++){
      map[i][pt++] = vec[q].second;
      if(pt > 100) break;
      map[i][pt++] = vec[q].first;
      if(pt > 100) break;
    }

    next_col = max(next_col,pt-1);
    col_num[i] = pt;
  }

  col = next_col;

  for(int i = 0 ; i <= row ; i++){
    for(int j = col_num[i] ; j <= col ; j++){
      map[i][j] = 0;
    }
  }

  return;
}

void C_function(void){
  vector<int> row_num(col+1);
  int next_row = row;

  for(int j = 0 ; j <= col ; j++){
    fill(&cnt[0],&cnt[100],0);
    for(int i = 0 ; i <= row ; i++) cnt[map[i][j]]++;

    vector<pair<int,int> > vec;

    cnt[0] = 0;
    for(int i = 0 ; i <= row ; i++){
      int cur = map[i][j];
      if(cnt[cur]){
        vec.pb(mp(cnt[cur],cur));
        cnt[cur] = 0;
      }
    }

    sort(vec.begin(),vec.end());

    int pt = 0;
    for(int q = 0 ; q < vec.size() ; q++){
      map[pt++][j] = vec[q].second;
      if(pt > 100) break;
      map[pt++][j] = vec[q].first;
      if(pt > 100) break;
    }

    next_row = max(next_row,pt-1);
    row_num[j] = pt;
  }

  row = next_row;

  for(int j = 0 ; j <= col ; j++){
    for(int i = row_num[j] ; i <= row ; i++){
      map[i][j] = 0;
    }
  }

  return;
}

void go(void){
  if(ans > 100){
    ans = -1;
    return;
  }

  if(r-1 <= row && c-1 <= col){
    if(map[r-1][c-1] == k) return;
  }

  if(row >= col) R_function();
  else C_function();


  ans++;
  go();
  return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&map[0][0], &map[100][100], 0);

    cin >> r >> c >> k;

    for(int i = 0 ; i < 3 ; i++){
      for(int j = 0 ; j < 3 ; j++){
        cin >> map[i][j];
      }
    }

    go();

    cout << ans << '\n';
    return 0;
}
