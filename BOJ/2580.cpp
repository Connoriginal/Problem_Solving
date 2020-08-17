#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int map[9][9];
bool wid[9][10];
bool ver[9][10];
bool sq[9][10];
bool print = false;

int square(int i, int j){
  if(0<= i && i < 3 && 0 <= j && j < 3) return 0;
  if(3 <= i && i < 6 && 0 <= j && j < 3) return 1;
  if(6 <= i && i < 9 && 0 <= j && j < 3) return 2;
  if(0 <= i && i < 3 && 3 <= j && j < 6) return 3;
  if(3 <= i && i < 6 && 3 <= j && j < 6) return 4;
  if(6 <= i && i < 9 && 3 <= j && j < 6) return 5;
  if(0 <= i && i < 3 && 6 <= j && j < 9) return 6;
  if(3 <= i && i < 6 && 6 <= j && j < 9) return 7;
  if(6 <= i && i < 9 && 6 <= j && j < 9) return 8;
  return 0;
}


bool solve(int p){
  if(p == 81){
    if(!print){
      print = true;
      for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
          printf("%d ",map[i][j]);
        }
        printf("\n");
      }
    }
    return true;;
  }

  int w = p/9, v = p%9;
  if(map[w][v] != 0){
    return solve(p+1);
  }
  else{
    for(int i = 1 ; i < 10 ; i++){
      if(!wid[w][i] && !ver[v][i] && !sq[square(w,v)][i]){
        map[w][v] = i;
        wid[w][i] = true;
        ver[v][i] = true;
        sq[square(w,v)][i] = true;
        if(solve(p+1)) return true;
        map[w][v] = 0;
        wid[w][i] = false;
        ver[v][i] = false;
        sq[square(w,v)][i] = false;
      }
    }
  }
  return false;
}

int main(void) {
  for(int i = 0 ; i < 9 ; i++){
    for(int j = 0 ; j < 9 ; j++){
      scanf("%d",&map[i][j]);
      if(map[i][j] != 0){
        wid[i][map[i][j]] = true;
        ver[j][map[i][j]] = true;
        sq[square(i,j)][map[i][j]] = true;
      }
    }
  }


  solve(0);
  return 0;
}
