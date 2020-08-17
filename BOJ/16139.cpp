#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sum[200001][30];

int main(void){
  char str[200001];
  scanf("%s",str);

  int len = strlen(str);

  for(int i = 1 ; i <= len ; i++){
    for(int j = 0 ; j <= 'z' - 'a' ; j++){
      sum[i][j] = sum[i-1][j];
    }
    sum[i][str[i-1] - 'a']++;
  }

  int n;
  scanf("%d",&n);

  while(n--){
    char c;
    int s,e;
    scanf(" %c %d %d",&c,&s,&e);
    printf("%d\n",sum[e+1][c-'a'] - sum[s][c-'a']);
  }

  return 0;
}
