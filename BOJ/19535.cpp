#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  vector<vector<int> > node(n+1);

  for(int i = 0 ; i < n-1 ; i++){
    int u,v;
    scanf("%d %d",&u,&v);

    node[u].pb(v);
    node[v].pb(u);
  }

  long long cnt_d = 0, cnt_g = 0;

  for(int i = 1 ; i <= n ; i++){
    int len = node[i].size();
    if(len >= 2){
      for(int j = 0 ; j < len ; j++){
        int cur = node[i][j];
        int temp_len = node[cur].size();
        if(temp_len >= 2){
          cnt_d += (len-1) * (temp_len - 1);
        }
      }
      if(len >= 3) cnt_g += len * (len-1) * (len-2) / 6;
    }
  }

  cnt_d /= 2;
  cnt_g *=3;
  if(cnt_d > cnt_g) printf("D\n");
  else if(cnt_d == cnt_g) printf("DUDUDUNGA\n");
  else printf("G\n");
  return 0;
}
