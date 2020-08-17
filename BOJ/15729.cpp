#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[1000001], b[1000001];

bool check(int a[], int b[] , int n){
  for(int i = 0 ; i < n ; i++){
    if(a[i] != b[i]) return false;
  }
  return true;
}

int main(void){
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++) scanf("%d",&b[i]);

  int ans = 0;
  while(!check(a,b,n)){
    for(int i = 0 ; i < n ; i++){
      if(a[i] != b[i]){
        a[i] = 1 - a[i];
        if(i+1 < n) a[i+1] = 1 - a[i+1];
        if(i+2 < n) a[i+2] = 1 - a[i+2];
        ans++;
      }
    }
  }

  printf("%d\n",ans);
  return 0;
}
