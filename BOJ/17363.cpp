#include <iostream>
#include <cstdio>

using namespace std;

char a[101][101];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < n ; i++){
    getchar();
    for(int j = 0 ; j < m ; j++){
      scanf("%c",&a[m - 1 - j][i]);
      if(a[m - 1 - j][i] == '-') a[m - 1 - j][i] = '|';
      else if(a[m - 1 - j][i] == '|') a[m - 1 - j][i] = '-';
      else if(a[m - 1 - j][i] == '/') a[m - 1 - j][i] = '\\';
      else if(a[m - 1 - j][i] == '\\') a[m - 1 - j][i] = '/';
      else if(a[m - 1 - j][i] == '^') a[m - 1 - j][i] = '<';
      else if(a[m - 1 - j][i] == '<') a[m - 1 - j][i] = 'v';
      else if(a[m - 1 - j][i] == 'v') a[m - 1 - j][i] = '>';
      else if(a[m - 1 - j][i] == '>') a[m - 1 - j][i] = '^';
    }
  }

  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      printf("%c",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
