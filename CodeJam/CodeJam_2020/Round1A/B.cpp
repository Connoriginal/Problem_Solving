#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int pascal[501][501];
bool check[501][501];

int dr[] = {-1,-1,0,0,1,1};
int dk[] = {-1,0,-1,1,0,1};

using namespace std;

int test_case;

int get_pas(int r, int k){
  if(k == 1 || r == k) return 1;
  if(pascal[r][k] > 0) return pascal[r][k];
  return pascal[r][k] = get_pas(r-1,k-1) + get_pas(r-1,k);
}

bool go(int r, int k, int sum, int n, vector<pair<int, int> > ans){
  sum += get_pas(r,k);
  ans.push_back(make_pair(r,k));
  if(sum == n){
    for(int i = 0 ; i < ans.size() ; i++){
      printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return true;
  }
  else if(sum > n){
    return false;
  }

  for(int i = 0 ; i < 6 ; i++){
    int nr = r + dr[i]; int nk = k + dk[i];
    if(0 < nr && nr <= 500 && 0 < nk && nk <= nr){
      if(!check[nr][nk]){
        check[nr][nk] = true;
        if(go(nr,nk,sum,n,ans)){
          return true;
        }
        check[nr][nk] = false;
      }
    }
  }
  return false;
}

int main(void){
  scanf("%d",&test_case);
  for(int i = 1 ; i <= test_case ; i++){
    int n;
    scanf("%d",&n);

    vector<pair<int, int> > ans;

    printf("Case #%d :\n",i);
    check[1][1] = true;
    go(1,1,0,n,ans);
  }
  return 0;
}
