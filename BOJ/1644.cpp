#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,l,r,cnt,sum;
vector<int> vec;

int main(void){
  scanf("%d",&n);
  vector<bool> prime(n+1); // false - 소수, true - 소수x
  for(int i = 2 ; i*i <= n ; i++){
    if(!prime[i]){
      for(int j = i * i ; j <= n ; j+= i) prime[j] = true;
    }
  }

  for(int i = 2 ; i <= n ; i++){
    if(!prime[i]) vec.push_back(i);
  }

  while(true){
    if(sum < n){
      if(r == vec.size()) break;
      sum += vec[r];
      r++;
    }else{
      sum -= vec[l];
      l++;
    }
    if(sum == n) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}
