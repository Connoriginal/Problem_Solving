#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int height, width;
int map[1001][1001];

int main(void){
  scanf("%d %d",&height,&width);
  for(int i = 0 ; i < height ; i++){
    for(int j = 0 ; j < width ; j++){
      scanf("%d",&map[i][j]);
    }
  }

  if(height % 2 == 1){
    for(int i = 0 ; i < height ; i++){
      for(int j = 0 ; j < width - 1 ; j++){
        if(i % 2 == 0){
          printf("R");
        }
        else{
          printf("L");
        }
      }
      if(i != height - 1){
        printf("D");
      }
    }
  }

  else{
    if(width % 2 == 1){
      for(int i = 0 ; i < width ; i++){
        for(int j = 0 ; j < height - 1 ; j++){
          if(i % 2 == 0){
            printf("D");
          }
          else{
            printf("U");
          }
        }
        if(i != width - 1){
          printf("R");
        }
      }
    }
    else{
      // 건너 뛰어야할 높이 = x , 너비 = y 구하기
      int temp = 1000, x = 0, y = 1;
      for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
          if((i + j) % 2 == 1 && map[i][j] < temp){
            x = i; y = j;
            temp = map[i][j];
          }
        }
      }

      //x,y 전까지 이동
      int val = (x%2 == 0) ? x : x-1;
      for(int i = 0 ; i < val ; i++){
        for(int j = 0 ; j < width-1 ; j++){
          if(i % 2 == 0){
            printf("R");
          }
          else{
            printf("L");
          }
        }
        printf("D");
      }

      //변동 되는 1. y전까2
      for(int i = 0 ; i < y/2 ; i++){
        printf("DRUR");
      }
      //2. x,y 피해서 이동
      if(x % 2 == 0){
        printf("DR");
      }
      else{
        printf("RD");
      }
      //3. 다음 줄로 이동
      for(int i = 0 ; i < (width - y - 1)/2 ; i++){
        printf("RURD");
      }

      //마지막
      for(int i = (x % 2 == 0) ? x + 2 : x + 1 ; i < height ; i++){
        printf("D");
        for(int j = 0 ; j < width - 1 ; j++){
          if(i % 2 == 0){
            printf("L");
          }
          else{
            printf("R");
          }
        }
      }

    }
  }


  printf("\n");
  return 0;
}
