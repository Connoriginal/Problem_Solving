#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
  long long k;
  int n,m;
  scanf("%d %d %lld",&n,&m,&k);

  if(m < 2) {
    printf("YES\n");
    return 0;
  }

  vector<int> vec(n+1);

  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&vec[i]);
  }

  vector<pair<int,int> > a(m);

  for(int i = 0 ; i < m ; i++){
    scanf("%d %d",&a[i].first,&a[i].second);
    if(a[i].first > a[i].second) swap(a[i].first,a[i].second);
    if(a[i].first == 1 && a[i].second == n) swap(a[i].first,a[i].second);
  }

  sort(a.begin(),a.end());

  long long ans = 0;

  int pt = 0;
  while(pt < m){
    int l = a[(pt + m -1) % m].second, r = a[pt].first;

    int temp = 1000001;
    if(l > r){
      for(int i = l ; i < n ; i++) temp = min(temp,vec[i]);
      for(int i = 1 ; i <= r ; i++) temp = min(temp,vec[i]);
    }else{
      for(int i = l ; i <= r ; i++) temp = min(temp, vec[i]);
    }

    ans += temp;
    pt++;
  }



  if(k >= ans) printf("YES\n");
  else printf("NO\n");

  return 0;
}
