#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Rule{
  int a,b,c;
};

int main(void){
  int n,k,d;
  scanf("%d %d %d",&n,&k,&d);
  vector<Rule> vec(k);

  for(int i = 0 ; i < k ; i++){
    scanf("%d %d %d",&vec[i].a, &vec[i].b, &vec[i].c);
  }

  int lp = 0, rp = n;

  while(lp + 1 < rp){

    int mid = (lp+rp)/2;

    long long sum = 0;
    for(int i = 0 ; i < k ;i++){
      if(vec[i].a <= mid){
        sum+=((min(vec[i].b,mid) - vec[i].a)/vec[i].c) + 1;
      }
    }

    if(sum >= d){
      rp = mid;
    }
    else{
      lp = mid;
    }
  }

  printf("%d\n",rp);

  return 0;
}
