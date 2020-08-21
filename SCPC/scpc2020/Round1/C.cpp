#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int test_case = 1 ; test_case <= t ; test_case++){
      int n,k,m;

      cin >> n >> k >> m;

      vector<vector<int> > ans(n+1,vector<int>(n+1,-1));
      vector<pair<int,int> > edge(k);

      for(int i = 0 ; i < k ; i++){
        cin >> edge[i].first >> edge[i].second;
      }


      for(int i = 1 ; i <= n ; i++){
        ans[i][i] = 0;
        for(int j = 0 ; j < k ; j++){
          int u = edge[j].first, v = edge[j].second;
          if(ans[i][u] != -1 && ans[i][v] != -1){
            int tmp_u = ans[i][u];
            int tmp_v = ans[i][v];
            ans[i][u] = min(tmp_u+1,tmp_v);
            ans[i][v] = min(tmp_v+1,tmp_u);
          }else if(ans[i][u] != -1 && ans[i][v] == -1){
            ans[i][v] = ans[i][u];
            ans[i][u]++;
          }else if(ans[i][u] == -1 && ans[i][v] != -1){
            ans[i][u] = ans[i][v];
            ans[i][v]++;
          }
        }
      }

      long long cnt = 0;
      while(m--){
        int a,b;
        cin >> a >> b;
        cnt += ans[a][b];
      }
      cout << "Case #" << test_case << '\n';
      cout << cnt << '\n';

    }
    return 0;
}
