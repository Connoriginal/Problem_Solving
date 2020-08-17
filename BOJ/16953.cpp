#include <iostream>
#include <cstdio>

using namespace std;

long long a,b;

int go(long long a, long long b){
  if(a > b) return -1;
  if(a == b) return 1;

  int fst = go(a*2,b);
  int sec = go((a*10)+1,b);

  if(fst==-1 && sec==-1) return -1;
  else if(fst == -1) return 1 + sec;
  else if(sec == -1) return 1 + fst;
  else return 1 + ((fst > sec) ? sec : fst);
}

int main(void){
  scanf("%lld %lld",&a,&b);
  printf("%d\n",go(a,b));
  return 0;
}
