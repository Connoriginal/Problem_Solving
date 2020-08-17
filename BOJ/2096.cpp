#include <iostream>
#include <cstdio>

using namespace std;

int max3(int a, int b, int c){
  return max(a,max(b,c));
}

int min3(int a, int b, int c){
  return min(a,min(b,c));
}

int main(void){
  int n;
  scanf("%d",&n);

  int max_score1,max_score2,max_score3;
  int min_score1,min_score2,min_score3;

  scanf("%d %d %d",&max_score1,&max_score2,&max_score3);
  min_score1 = max_score1;min_score2 = max_score2;min_score3 = max_score3;

  for(int i = 1 ; i < n ; i++){
    int temp1,temp2,temp3; // 최대값
    int val1,val2,val3; // 최소값
    int a, b, c;
    scanf("%d %d %d",&a,&b,&c);

    temp1 = max(max_score1,max_score2) + a;temp2 = max3(max_score1,max_score2,max_score3) + b;temp3 = max(max_score2,max_score3) + c;
    val1 = min(min_score1,min_score2) + a;val2 = min3(min_score1,min_score2,min_score3) + b;val3 = min(min_score2,min_score3) + c;

    max_score1 = temp1;max_score2=temp2;max_score3=temp3;
    min_score1 = val1;min_score2=val2;min_score3=val3;
  }

  printf("%d %d\n",max3(max_score1,max_score2,max_score3),min3(min_score1,min_score2,min_score3));
  return 0;
}
